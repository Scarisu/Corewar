/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:21:56 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/20 16:44:34 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void 	need_arg(t_asm *e)
{
	ft_putstr_fd(WHITE "Not enought arguments, opcode \"" GREY, 2);
	ft_putstr_fd(e->verbos.opcode_name, 2);
	ft_memdel((void **)&e->verbos.opcode_name);
	ft_putstr_fd(WHITE "\" need {" GREY, 2);
	ft_putnbr_fd(g_op_tab[e->verbos.opcode].nb_params, 2);
	ft_putstr_fd(WHITE "} argument", 2);
	g_op_tab[e->verbos.opcode].nb_params > 1 ? ft_putchar_fd('s', 2) : 0;
}

void 	wrong_arg(t_asm *e)
{

	ft_putstr_fd(WHITE "Wrong argument, \"" GREY, 2);
	ft_putstr_fd(e->verbos.opcode_name, 2);
	ft_memdel((void **)&e->verbos.opcode_name);
	ft_putstr_fd(WHITE "\" expect {" GREY, 2);
	//
	ft_putstr_fd(WHITE "}", 2);
}

void	not_enought_arg(t_asm *e)
{
	ft_memdel((void **)&e->verbos.opcode_name);
	//
	ft_putstr_fd(WHITE "NOT ENOUGHT ARG", 2);
	(void)e;
}
