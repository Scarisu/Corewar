/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:23 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/31 00:35:48 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_or_loop(t_corewar *d, t_reg *reg, t_ocp ocp, int pc)
{
	int		i;
	int		r[3];
	int		len[2];

	i = -1;
	len[1] = 0;
	while (++i < 3)
	{
		len[0] = 1;
		if (ocp.p[i] == O_DIR && (len[0] = 4))
			r[i] = find_hexa(d->map, pc, len[0]);
		else if (ocp.p[i] == O_IND && (len[0] = 2))
		{
			if ((r[i] = find_hexa(d->map, pc, len[0])) > 65536 / 2)
				r[i] -= 65536;
			r[i] = find_hexa(d->map, pc + r[i] - len[0] - 1, len[0] + 2);
		}
		else
			r[i] = d->map[pc] - 1;
		(pc += len[0]) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		len[1] += len[0];
	}
	reg->r[r[2]] = r[0] | r[1];
	reg->carry = !reg->r[r[2]] ? 1 : 0;
	jump_to_next(d, reg, len[1] + 2, false);
}

void	op_or(t_corewar *d, t_reg *reg)
{
	int		pc;
	t_ocp	ocp;

	if (++reg->cycle == 7 && !(reg->cycle = 0))
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[pc])) &&
				(false_cmd(d, reg, true)))
			return ;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		op_or_loop(d, reg, ocp, pc);
	}
}
