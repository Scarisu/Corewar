/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:40 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/04 00:54:44 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_zjmp(t_corewar *d, t_reg *reg)
{
	int		pc;

	if (++reg->cycle == 20 && !(reg->cycle = 0))
	{
		if (reg->carry)
		{
			pc = find_hexa(d->map, reg->pc + 1, 2);
			true_pc(&pc);
			jump_to_next(d, reg, reg->pc + (pc % IDX_MOD), false);
		}
		else
			jump_to_next(d, reg, 3, false);
	}
}
