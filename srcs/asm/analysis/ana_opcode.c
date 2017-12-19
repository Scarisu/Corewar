/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:35:29 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/12 01:03:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ins_opcode(t_asm *e, char *line)
{
	int		ret;
	int		content_len;

	//printf("pos [%d]\n", e->bin.op_pos);
	if (!skip_tab(e, line))
		return (0);
	content_len = I;
	while (line[content_len] && line[content_len] != ' '
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
	e->enco->opcode = g_op_tab[e->verbos.opcode].opcode;
	ret = check_param(e, e->enco, line);
	ft_memdel((void **)&e->verbos.opcode_name);
	e->bin.op_pos += opcode_position(e->enco);
	e->enco->next = set_enco(e);
	e->enco = e->enco->next;
	return (ret);
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

int		opcode_position(t_enco *i)
{
	int	pos;
	int	nb_arg;

	pos = 1;
	nb_arg = -1;
	pos += (i->opcode != LIVE && i->opcode != ZJMP &&
			i->opcode != LFORK && i->opcode != AFF) ? 1 : 0;
	while (++nb_arg < i->nb_arg)
	{
		pos += (i->arg[nb_arg].type == T_REG) ? 1 : 2;
		pos += (i->arg[nb_arg].type == T_IND) ? 2 : 0;
		pos += (i->arg[nb_arg].type == T_DIR && (i->opcode == LIVE ||
			i->opcode == LD || i->opcode == AND || i->opcode == OR ||
			i->opcode == XOR || i->opcode == LLD)) ? 2 : 0;
	}
	return (pos);
}
