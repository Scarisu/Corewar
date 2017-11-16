/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:35:29 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/16 20:31:32 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		ins_label(t_asm *e, char *line)
{
	int	content_len;

	content_len = I;
	while (line[content_len]
		&& line[content_len] != LABEL_CHAR
		&& line[content_len] != ' ')
			++content_len;
	if (line[content_len] != LABEL_CHAR)
		return (1);
	content_len -= I;
	if (!(e->champ.valid.label->name = ft_strsub(line, I, content_len)))
		error(e, MALLOC);
	if (!valid_label(e->champ.valid.label->name))
		return (verbos(e, INVALID_LABEL));
	e->champ.valid.label->next = set_label(e, (int[2]){e->verbos.nb_line, I});
	e->champ.valid.label = e->champ.valid.label->next;
	I += content_len + 1;
	return (1);
}

int		valid_label(char *name)
{
	int		i;

	i = -1;
	if (!ft_strlen(name))
		return (0);
	while (name[++i])
		if (!ft_strchr(LABEL_CHARS, name[i]))
			return (0);
	return (1);
}

int		ins_opcode(t_asm *e, char *line)
{
	int		content_len;

	if (!skip_tab(e, line))
		return (verbos(e, SYNTAX));
	content_len = I;
	while (line[content_len]
		&& line[content_len] != ' '
		&& line[content_len] != '\n')
			++content_len;
	//if (line[content_len] != ' ')
		//return (verbos(e, INVALID_OPCODE));
	content_len -= I;
	if (!(e->verbos.opcode_name = ft_strsub(line, I, content_len)))
		error(e, MALLOC);
	if ((e->verbos.opcode = exist_opcode(e->verbos.opcode_name)) < 0)
		return (verbos(e, OPCODE_EXIST));
	I += content_len;
	return (check_param(e, e->verbos.opcode, line));
}

int		exist_opcode(char *opcode)
{
	int	i;

	i = 0;
	while (g_op_tab[i].name && ft_strcmp(opcode, g_op_tab[i].name))
		++i;
	if (!g_op_tab[i].name)
		return (-1);
	return (i);
}
