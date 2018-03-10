/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:27 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/10 08:22:04 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_st(t_corewar *d, t_reg *reg)
{
	int		r;
	int		pc;
	int		param;
	t_ocp	ocp;

	if (++reg->cycle == 5 && !(reg->cycle = 0))
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[pc])) && (false_command(d, reg, true)))
			return ;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if ((r = d->map[pc]) > 0 && r < 16)
		{
			(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			if (ocp.p[1] == O_IND)
			{
				if ((param = find_hexa(d->map, pc, 2)) > 65536 / 2)
					param -= 65536;
				put_hexa(d, reg->n, reg->pc + param, reg->r[r - 1]);
			}
			else
			{
				param = d->map[pc];
				reg->r[param - 1] = reg->r[r - 1];
			}
			pc = ocp.p[1] == O_IND ? 5 : 4;
			jump_to_next(d, reg, pc, false);
		}
		else
			jump_to_next(d, reg, 1, false);
	}
}
