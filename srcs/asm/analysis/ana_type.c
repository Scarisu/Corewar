/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:14:46 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/12 00:47:42 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		arg_reg(t_asm *e, char *line)
{
	int		content_len;
	int		nb_reg;
	char	*reg;

	content_len = I + 1;
	if (line[content_len] == '-')
		++content_len;
	while (line[content_len] >= '0' && line[content_len] <= '9')
		++content_len;
	if ((line[content_len] != ',' && line[content_len] != ' ' &&
		line[content_len] != '\n') || (I + 1) == content_len ||
		line[content_len - 1] == '-')
		return (verbos(e, INVALID_REG));
	if (!(reg = ft_strsub(line, I + 1, content_len - I - 1)))
		error(e, MALLOC);
	nb_reg = ft_atoi(reg);
	ft_memdel((void **)&reg);
	if (nb_reg < 1 || nb_reg > REG_NUMBER)
		return (verbos(e, INVALID_REG));
	put_bin(e, &e->bin.arg, (int[1]){nb_reg}, 1);
	I = content_len;
	return (1);
}

int		arg_val(t_asm *e, char *line, int type)
{
	int		content_len;
	char	*value;

	content_len = (I + 2 - type);
	if (line[content_len] == LABEL_CHAR)
		return (arg_lab(e, line, type));
	if (line[content_len] == '-')
		++content_len;
	while (line[content_len] >= '0' && line[content_len] <= '9')
		++content_len;
	if ((line[content_len] != ',' && line[content_len] != ' ' &&
		line[content_len] != '\n') || (I + 2 - type) == content_len ||
		line[content_len - 1] == '-')
			return (verbos(e, (type == 1) ? INVALID_DIR_VAL : INVALID_IND_VAL));
	if (!(value = ft_strsub(line, I + 2 - type, content_len - I - (2 - type))))
		error(e, MALLOC);
	put_bin(e, &e->bin.arg, (int[1]){ft_atoi(value)}, 1);
	ft_memdel((void **)&value);
	I = content_len;
	return (1);
}

int		arg_lab(t_asm *e, char *line, int type)
{
	int		content_len;
	char	*label;

	content_len = (I + 4 - (type * 2));
	while (line[content_len] != ',' && line[content_len] != ' '
		&& line[content_len] != '\n')
		++content_len;
	if (!(label = ft_strsub(line, I + 3 - type, content_len - I - (3 - type))))
		error(e, MALLOC);
	if (!valid_label(label))
	{
		ft_memdel((void **)&label);
		return (verbos(e, INVALID_LABEL_ARG));
	}
	e->enco->arg_label = set_label(e, (int[2]){e->verbos.nb_line, I});
	e->enco->arg_label->type = (type == 1) ? T_DIR : T_IND;
	//e->enco->arg_label->octets = e->size;
	!(e->enco->arg_label->name = ft_strdup(label)) ? error(e, MALLOC) : 0;
	ft_memdel((void **)&label);
	!(e->enco->arg_label->line = ft_strdup(line)) ? error(e, MALLOC) : 0;
	e->enco->next = set_enco(e);
	e->enco = e->enco->next;
	I = content_len;
	return (1);
}
