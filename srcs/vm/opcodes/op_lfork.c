/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:02 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/29 07:00:45 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_lfork(t_corewar *d, t_reg *reg)
{
	int		pc;
	t_reg	*tmp;

	if (++reg->cycle == 1000 && !(reg->cycle = 0))
	{
		tmp = reg;
		if ((pc = find_hexa(d->map, reg->pc + 1, 2)) > 65535 / 2)
			pc -= 65535;
		tmp = fork_reg(reg, pc, false);
		d->champs[reg->n - 1].reg = tmp;
		jump_to_next(d, reg, 3, true);
		jump_to_next(d, tmp, pc, false);
	}
}
