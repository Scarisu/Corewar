/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:40 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 15:14:41 by rlecart          ###   ########.fr       */
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
			if ((pc = find_hexa(d->map, reg->pc + 1, 2)) > 65536 / 2)
				pc -= 65536;
			jump_to_next(reg, get_modulo(pc, IDX_MOD));
		}
		else
			jump_to_next(reg, 3);
	}
}
