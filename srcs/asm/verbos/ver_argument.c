/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:21:56 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/16 20:50:41 by pbernier         ###   ########.fr       */
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

void	invalid_reg(t_asm *e)
{
	ft_memdel((void **)&e->verbos.opcode_name);
	ft_putstr_fd(WHITE "Invalid register, must be a positive number ", 2);
	ft_putstr_fd("lower or equal to ", 2);
	ft_putnbr_fd(REG_NUMBER, 2);
	(void)e;
}

void	not_enought_arg(t_asm *e)
{
	ft_memdel((void **)&e->verbos.opcode_name);
	//
	ft_putstr_fd(WHITE "NOT ENOUGHT ARG", 2);
	(void)e;
}

void	invalid_arg_label(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.check->name)) > 30)
		e->verbos.len_arrow = 30;
	ft_memdel((void **)&e->champ.valid.check->name);
	ft_putstr_fd(WHITE "Label can't be null and ", 2);
	ft_putstr_fd("must only contain {" GREY LABEL_CHARS WHITE "}", 2);
}

void	invalid_dir(t_asm *e)
{
	(void)e;
}
