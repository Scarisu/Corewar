/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:34 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 12:05:14 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_sub(t_corewar *d, t_reg *reg)
{
	int		i;
	int		pc;
	int		r[3];
	t_ocp	ocp;

	if (++reg->cycle == 10 && !(reg->cycle = 0))
	{
		i = -1;
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[pc])) &&
				(false_cmd(d, reg, true)))
			return ;
		while (++i < 3)
		{
			(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			if (((r[i] = d->map[pc] - 1) < 0 || r[i] > 16) &&
					(false_cmd(d, reg, true)))
				return ;
		}
		reg->r[r[2]] = reg->r[r[0]] - reg->r[r[1]];
		jump_to_next(reg, 5);
		reg->carry = !reg->r[r[2]] ? 1 : 0;
	}
}
