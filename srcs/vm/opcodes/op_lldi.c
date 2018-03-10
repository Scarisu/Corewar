/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:18 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/10 08:21:55 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_lldi(t_corewar *d, t_reg *reg)
{
	int		i;
	int		pc;
	int		tmp;
	int		r[3];
	t_ocp	ocp;

	if (++reg->cycle == 25 && !(reg->cycle = 0))
	{
		i = -1;
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[pc])) && (false_command(d, reg, true)))
			return ;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		while (++i < 3)
		{
			tmp = ocp.p[i] == O_REG ? 1 : 2;
			r[i] = find_hexa(d->map, pc, tmp);
			if (i < 2 && ocp.p[i] == O_REG && r[i] >= 1 && r[i] <= 16)
				r[i] = reg->r[r[i] - 1];
			else if (i < 2 && ocp.p[i] == O_REG && (false_command(d, reg, true)))
				return ;
			(pc += tmp) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		}
		tmp = reg->pc - (r[0] + r[1]);
		true_pc(&tmp);
		if (r[2] >= 1 && r[2] <= 16)
			reg->r[r[2] - 1] = find_hexa(d->map, tmp, 4);
		reg->carry = !reg->r[r[2] - 1] ? 1 : 0;
		jump_to_next(d, reg, pc - reg->pc, false);
	}
}
