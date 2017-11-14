/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:36:15 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/14 22:22:03 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	invalid_label(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.label->name)) > 30)
		e->verbos.len_arrow = 30;
	ft_memdel((void **)&e->champ.valid.label->name);
	ft_putstr_fd(WHITE "Label can't be null and ", 2);
	ft_putstr_fd("must only contain {" GREY LABEL_CHARS WHITE "}", 2);
}

void	invalid_opcode(t_asm *e)
{
	ft_putstr_fd(WHITE "Invalid opcode", 2);
	(void)e;
}

void 	opcode_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->verbos.opcode)) - 1 > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Opcode \"" GREY, 2);
	ft_putstr_fd(e->verbos.opcode, 2);
	ft_memdel((void **)&e->verbos.opcode);
	ft_putstr_fd(WHITE "\" doesn't exist", 2);
}

/*
** void	syntax(t_asm *e);
*/
