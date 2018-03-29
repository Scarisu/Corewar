/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:52 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/29 08:57:34 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_ld(t_corewar *d, t_reg *reg)
{
	int		r;
	int		pc;
	int		param;
	t_ocp	ocp;

	if (++reg->cycle == 5 && !(reg->cycle = 0))
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[pc])) &&
				(false_command(d, reg, true)))
			return ;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (ocp.p[0] == O_IND)
		{
			if ((param = find_hexa(d->map, pc, 2)) > 65535 / 2)
				param -= 65535;
			param = find_hexa(d->map, reg->pc + (param % IDX_MOD), 4);
		}
		else
			param = find_hexa(d->map, pc, 4);
		pc = ocp.p[0] == O_IND ? 4 : 6;
		jump_to_next(d, reg, pc, false);
		if (((r = d->map[reg->pc]) < 1 || r > 16) &&
				(false_command(d, reg, true)))
			return ;
		reg->r[r - 1] = param;
		jump_to_next(d, reg, 1, false);
		reg->carry = !param ? 1 : 0;
	}
}
