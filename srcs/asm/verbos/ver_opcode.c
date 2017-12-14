/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:36:15 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/29 19:57:21 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	invalid_opcode(t_asm *e)
{
	add_cont(e, &V_LINE, WHITE "Invalid opcode");
	(void)e;
}

void	opcode_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->verbos.opcode_name) - 1) > 30)
		e->verbos.len_arrow = 30;
	add_cont(e, &V_LINE, WHITE "Opcode \"" GREY);
	add_cont(e, &V_LINE, e->verbos.opcode_name);
	ft_memdel((void **)&e->verbos.opcode_name);
	add_cont(e, &V_LINE, WHITE "\" doesn't exist");
}

/*
** void	syntax(t_asm *e);
*/
