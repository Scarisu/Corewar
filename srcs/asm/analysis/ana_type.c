/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:14:46 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/11 23:45:15 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		arg_reg_value(t_asm *e, char *line)
{
	int		content_len;
	int		nb_reg;
	char	*reg;

	while (line[I] == ' ')
		++I;
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
	add_cont(e, &e->enco->hexa, (char[2]){nb_reg, '\0'});
	I = content_len;
	return (1);
}

int		arg_dir_value(t_asm *e, char *line)
{
	int		content_len;
	char	*value;

	while (line[I] == ' ')
		++I;
	content_len = I + 1;
	if (line[content_len] == LABEL_CHAR)
		return (arg_dir_label(e, line));
	if (line[content_len] == '-')
		++content_len;
	while (line[content_len] >= '0' && line[content_len] <= '9')
		++content_len;
	if ((line[content_len] != ',' && line[content_len] != ' ' &&
		line[content_len] != '\n') || (I + 1) == content_len ||
		line[content_len - 1] == '-')
		return (verbos(e, INVALID_DIR_VAL));
	if (!(value = ft_strsub(line, I + 1, content_len - I - 1)))
		error(e, MALLOC);
	add_cont(e, &e->enco->hexa, (char[2]){ft_atoi(value), '\0'});
	ft_memdel((void **)&value);
	I = content_len;
	return (1);
}

int		arg_dir_label(t_asm *e, char *line)
{
	int		content_len;
	char	*label;

	content_len = I + 2;
	while (line[content_len] != ',' && line[content_len] != ' '
		&& line[content_len] != '\n')
		++content_len;
	if (!(label = ft_strsub(line, I + 2, content_len - I - 2)))
		error(e, MALLOC);
	if (!valid_label(label))
	{
		ft_memdel((void **)&label);
		return (verbos(e, INVALID_LABEL));
	}
	e->enco->next = set_enco(e);
	e->enco = e->enco->next;
	e->enco->arg_label = set_label(e, (int[2]){e->verbos.nb_line, I});
	if (!(e->enco->arg_label->name = ft_strdup(label)))
		error(e, MALLOC);
	ft_memdel((void **)&label);
	if (!(e->enco->arg_label->line = ft_strdup(line)))
		error(e, MALLOC);
	I = content_len;
	return (1);
}

int		arg_ind_value(t_asm *e, char *line)
{
	int		content_len;

	while (line[I] == ' ')
		++I;
	content_len = I + 1;
	if (line[content_len] && (
		line[content_len] == '-' ||
		line[content_len] == '+'))
		++content_len;
	while (line[content_len] &&
		(line[content_len] >= '0' || line[content_len] >= '9'))
		++content_len;
	if (line[content_len] &&
		line[content_len] != ',' &&
		line[content_len] != ' ' &&
		line[content_len] != '\n')
		return (0);
	I = content_len;
	return (1);
}

int		arg_ind_label(t_asm *e, char *line)
{
	(void)e;
	(void)line;
	// int	content_len;
    //
	// content_len = I + 2;
	// while (line[content_len]
	// 	&& line[content_len] != ','
	// 	&& line[content_len] != ' '
	// 	&& line[content_len] != '\n')
	// 	++content_len;
	// content_len -= I + 2;
	// if (!(e->champ.valid.check->name = ft_strsub(line, I + 2, content_len)))
	// 	error(e, MALLOC);
	// if (!valid_label(e->champ.valid.check->name))
	// 	return (verbos(e, INVALID_ARG_LABEL));
	// e->champ.valid.check->next = set_label(e, (int[2]){e->verbos.nb_line, I});
	// e->champ.valid.check = e->champ.valid.check->next;
	// I += content_len + 2;
	return (1);
}
