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
	int	i;
	int t[MAX_ARGS_NUMBER];

	i = -1;
	ft_memcpy(t, g_op_tab[e->verbos.opcode].type,
		sizeof(int[MAX_ARGS_NUMBER]));
	add_cont(e, &V_LINE, WHITE "Wrong argument, \"" GREY);
	add_cont(e, &V_LINE, e->verbos.opcode_name);
	add_cont(e, &V_LINE, WHITE "\" expect {" GREY);
	while (++i < g_op_tab[e->verbos.opcode].nb_params)
	{
		t[i] % 2 ? add_cont(e, &V_LINE, GREY "T_REG" WHITE) : 0;
		t[i] != 1 && t[i] != 2 && t[i] != 4 ? add_cont(e, &V_LINE, " | ") : 0;
		t[i] == 2 || t[i] == 3 || t[i] == 6 || t[i] == 7 ?
			add_cont(e, &V_LINE, GREY "T_DIR" WHITE) : 0;
		t[i] == 7 ? add_cont(e, &V_LINE, " | ") : 0;
		t[i] >= 4 && t[i] <= 7 ? add_cont(e, &V_LINE, GREY "T_IND" WHITE) : 0;
		if (i < g_op_tab[e->verbos.opcode].nb_params - 1)
			add_cont(e, &V_LINE, ", ");
	}
	ft_memdel((void **)&e->verbos.opcode_name);
	add_cont(e, &V_LINE, WHITE "}");
}

void	too_many_arg(t_asm *e)
{
	char	*nbr;

	nbr = NULL;
	add_cont(e, &V_LINE, WHITE "Too many arguments, opcode \"" GREY);
	add_cont(e, &V_LINE, e->verbos.opcode_name);
	ft_memdel((void **)&e->verbos.opcode_name);
	add_cont(e, &V_LINE, WHITE "\" only need {" GREY);
	if (!(nbr = ft_itoa(g_op_tab[e->verbos.opcode].nb_params)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
	add_cont(e, &V_LINE, WHITE "} argument");
	if (g_op_tab[e->verbos.opcode].nb_params > 1)
		add_cont(e, &V_LINE, "s");
}
