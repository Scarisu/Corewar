/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:21:56 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/11 21:49:44 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	need_arg(t_asm *e)
{
	char	*nbr;

	nbr = NULL;
	add_cont(e, &V_LINE, WHITE "Not enought arguments, opcode \"" GREY);
	add_cont(e, &V_LINE, e->verbos.opcode_name);
	ft_memdel((void **)&e->verbos.opcode_name);
	add_cont(e, &V_LINE, WHITE "\" need {" GREY);
	if (!(nbr = ft_itoa(g_op_tab[e->verbos.opcode].nb_params)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
	add_cont(e, &V_LINE, WHITE "} argument");
	if (g_op_tab[e->verbos.opcode].nb_params > 1)
		add_cont(e, &V_LINE, "s");
}

void	wrong_arg(t_asm *e)
{
	add_cont(e, &V_LINE, WHITE "Wrong argument, \"" GREY);
	add_cont(e, &V_LINE, e->verbos.opcode_name);
	ft_memdel((void **)&e->verbos.opcode_name);
	add_cont(e, &V_LINE, WHITE "\" expect {" GREY);
	add_cont(e, &V_LINE, WHITE "}");
}

void	not_enought_arg(t_asm *e)
{
	add_cont(e, &V_LINE, WHITE "NOT ENOUGHT ARG");
}
