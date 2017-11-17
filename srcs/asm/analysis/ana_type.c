/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:14:46 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/17 18:10:54 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		arg_reg_value(t_asm *e, char *line)
{
	int		content_len;
	int		nb_reg;
	char	*reg;

	content_len = I + 1;
	while (line[content_len] &&
		(line[content_len] >= '0' || line[content_len] >= '9'))
		++content_len;
	if (!(reg = ft_strsub(line, I + 1, content_len - I - 1)))
		error(e, MALLOC);
	nb_reg = ft_atoi(reg);
	ft_memdel((void **)&reg);
	if (nb_reg < 1 || nb_reg > REG_NUMBER || (
		line[content_len] &&
		line[content_len] != ',' &&
		line[content_len] != ' ' &&
		line[content_len] != '\n'))
		return (verbos(e, INVALID_REG));
	I = content_len;
	return (1);
}

int		arg_dir_value(t_asm *e, char *line)
{
	int		content_len;
	//char	*dir;

	content_len = I + 1;
	if (line[content_len] &&
		line[content_len] == LABEL_CHAR)
		return (arg_label(e, line));
	if (line[content_len] && (
		line[content_len] == '-' ||
		line[content_len] == '+'))
		++ content_len;
	while (line[content_len] &&
		(line[content_len] >= '0' || line[content_len] >= '9'))
		++content_len;
	//if (!(dir = ft_strsub(line, I + 1, content_len - I - 1)))
	//	error(e, MALLOC);
	//ft_memdel((void **)&dir);
	if (line[content_len] &&
		line[content_len] != ',' &&
		line[content_len] != ' ' &&
		line[content_len] != '\n')
		return (verbos(e, INVALID_DIR));
	I = content_len;
	return (1);
}

int		arg_ind_value(t_asm *e, char *line)
{
	int		content_len;
	//char	*ind;

	content_len = I + 1;
	if (line[content_len] && (
		line[content_len] == '-' ||
		line[content_len] == '+'))
		++content_len;
	while (line[content_len] &&
		(line[content_len] >= '0' || line[content_len] >= '9'))
		++content_len;
	//if (!(dir = ft_strsub(line, I + 1, content_len - I - 1)))
	//	error(e, MALLOC);
	//ft_memdel((void **)&dir);
	if (line[content_len] &&
		line[content_len] != ',' &&
		line[content_len] != ' ' &&
		line[content_len] != '\n')
		return (verbos(e, INVALID_DIR));
	I = content_len;
	return (1);
}

int		arg_label(t_asm *e, char *line)
{
	int	content_len;

	content_len = I + 2;
	while (line[content_len]
		&& line[content_len] != ','
		&& line[content_len] != ' '
		&& line[content_len] != '\n')
			++content_len;
	content_len -= I + 2;
	if (!(e->champ.valid.check->name = ft_strsub(line, I + 2, content_len)))
		error(e, MALLOC);
	if (!valid_label(e->champ.valid.check->name))
		return (verbos(e, INVALID_ARG_LABEL));
	e->champ.valid.check->next = set_label(e, (int[2]){e->verbos.nb_line, I});
	e->champ.valid.check = e->champ.valid.check->next;
	I += content_len;
	return (1);
}
