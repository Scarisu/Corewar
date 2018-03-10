/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:31 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/10 08:22:07 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_sti(t_corewar *d, t_reg *reg)
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
			if (ocp.p[i] == O_REG && r[i] >= 1 && r[i] <= 16)
				r[i] = reg->r[r[i] - 1];
			else if (ocp.p[i] == O_IND)
			{
				if (r[i] > 65535 / 2)
					r[i] -= 65535;
				r[i] = find_hexa(d->map, reg->pc + (r[i] % IDX_MOD), 4);
			}
			if (ocp.p[i] != O_REG && r[i] > 65536 / 2)
				r[i] -= 65536;
			(pc += tmp) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		}
		tmp = reg->pc + ((r[1] + r[2]) % IDX_MOD);
		true_pc(&tmp);
		put_hexa(d, reg->n, tmp, r[0]);
		jump_to_next(d, reg, pc - reg->pc, false);
	}
}
