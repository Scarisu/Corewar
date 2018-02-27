/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:18 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/27 04:05:21 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_lldi(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		i;
	int		pc;
	int		tmp;
	int		r[3];
	t_ocp	o;

	(void)champs;
	if (++reg->cycle == 25)
	{
		reg->cycle = 0;
		i = -1;
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		o = find_ocp(d->map[pc]);
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		while (++i < 3)
		{
			tmp = o.p[i] == O_REG ? 1 : 2;
			r[i] = find_hexa(d->map, pc, tmp);
			if (i < 2 && o.p[i] == O_REG && r[i] >= 1 && r[i] <= 16)
				r[i] = reg->r[r[i] - 1];
			(pc += tmp) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		}
		tmp = reg->pc - (r[0] + r[1]);
		while (tmp >= MEM_SIZE || tmp < 0)
		{
			if (tmp >= MEM_SIZE)
				tmp -= MEM_SIZE;
			else if (tmp < 0)
				tmp += MEM_SIZE;
		}
		if (r[2] >= 1 && r[2] <= 16)
			reg->r[r[2] - 1] = find_hexa(d->map, tmp, 4);
		jump_to_next(d, reg, pc - reg->pc, false);
	}
}
