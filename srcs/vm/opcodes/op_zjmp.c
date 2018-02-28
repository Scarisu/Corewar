/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:40 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/28 07:23:14 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_zjmp(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		pc;

	(void)champs;
	if (++reg->cycle == 20 && !(reg->cycle = 0))
	{
		if (reg->carry == 1)
		{
			if ((pc = find_hexa(d->map, reg->pc + 1, 2)) == -1)
				pc = reg->pc + 3;
			true_pc(&pc);
			jump_to_next(d, reg, MEM_SIZE - reg->pc + pc, false);
		}
		else
			jump_to_next(d, reg, 3, false);
	}
}
