/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:02 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/28 07:43:04 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_lfork(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		pc;
	t_reg	*tmp;

	(void)champs;
	if (++reg->cycle == 1000 && !(reg->cycle = 0))
	{
		tmp = reg;
		pc = find_hexa(d->map, reg->pc + 1, 2);
		reg = fork_reg(reg);
		jump_to_next(d, reg, pc, true);
		jump_to_next(d, tmp, 3, false);
	}
}
