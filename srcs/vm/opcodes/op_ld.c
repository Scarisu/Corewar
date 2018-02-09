/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:52 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/09 03:50:20 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_ld(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		r;
	int		pc;
	int		param;
	t_ocp	ocp;

	(void)champs;
	if (++reg->cycle == 5)
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		ocp = find_ocp(d->map[pc]);
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (ocp.p[0] == O_IND)
			param = find_hexa(d->map, pc, 2);
		else
			param = find_hexa(d->map, pc, 4);
		pc = ocp.p[0] == O_IND ? 4 : 6;
		jump_to_next(d, reg, pc, false);
		r = d->map[reg->pc];
		reg->r[r - 1] = param;
		jump_to_next(d, reg, 1, false);
		reg->carry = 1;
		reg->cycle = 0;
	}
}
