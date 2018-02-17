/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:40 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/17 03:02:56 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_zjmp(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		pc;

	(void)champs;
	if (++reg->cycle == 20)
	{
		if (reg->carry == 1)
		{
			if ((pc = find_hexa(d->map, reg->pc + 1, 2)) == -1)
				pc = reg->pc + 3;
			while (pc >= MEM_SIZE)
				pc -= MEM_SIZE;
			jump_to_next(d, reg, MEM_SIZE - reg->pc + pc, false);
			reg->cycle = 0;
		}
		else
			jump_to_next(d, reg, 3, false);
	}
}
