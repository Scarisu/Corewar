/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:02 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/16 23:44:22 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_lfork(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		pc;

	(void)champs;
	if (++reg->cycle == 1000)
	{
		reg->cycle = 0;
		pc = find_hexa(d->map, reg->pc + 1, 2);
		reg->next = fork_reg(reg);
		jump_to_next(d, reg->next, pc, true);
		jump_to_next(d, reg, 3, false);
	}
}
