/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:35:29 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/29 22:46:30 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

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
	if (line[content_len] != ' ')
		return (verbos(e, INVALID_OPCODE));
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
