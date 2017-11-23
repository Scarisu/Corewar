/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:36:15 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/23 03:06:00 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	invalid_opcode(t_asm *e)
{
	ft_putstr_fd(WHITE "Invalid opcode", 2);
	(void)e;
}

void 	opcode_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->verbos.opcode_name) - 1) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Opcode \"" GREY, 2);
	ft_putstr_fd(e->verbos.opcode_name, 2);
	ft_memdel((void **)&e->verbos.opcode_name);
	ft_putstr_fd(WHITE "\" doesn't exist", 2);
}

/*
** void	syntax(t_asm *e);
*/
