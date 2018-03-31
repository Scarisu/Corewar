/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:12 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/31 07:51:45 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		find_ind_lld(t_corewar *d, t_reg *reg, int pc)
{
	int		param;

	if ((param = find_hexa(d->map, pc, 2)) > 65536 / 2)
		param -= 65536;
	param = find_hexa(d->map, reg->pc + param, 4);
	return (param);
}

void	op_lld(t_corewar *d, t_reg *reg)
{
	int		r;
	int		pc;
	int		param;
	t_ocp	ocp;

	if (++reg->cycle == 5 && !(reg->cycle = 0))
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[pc])) &&
				(false_cmd(d, reg, true)))
			return ;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (ocp.p[0] == O_IND)
			param = find_ind_lld(d, reg, pc);
		else
			param = find_hexa(d->map, pc, 4);
		pc = ocp.p[0] == O_IND ? 4 : 6;
		jump_to_next(d, reg, pc, false);
		r = d->map[reg->pc];
		reg->r[r - 1] = param;
		jump_to_next(d, reg, 1, false);
		reg->carry = !param ? 1 : 0;
	}
}
