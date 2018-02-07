/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:52 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/07 19:10:11 by rlecart          ###   ########.fr       */
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
		(void)param;
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		ocp = find_ocp(pc);
		printw("o = %d\n", ocp.p[0]);
		printw("o = %d\n", ocp.p[1]);
		printw("o = %d\n", ocp.p[2]);
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (ocp.p[0] == O_IND)
			pc = find_hexa(d->map, pc, 4);
		else
			pc = find_hexa(d->map, pc, 2);
		printw("%d\n", pc);
		refresh();
		while (1);
		//(pc = d->map[(int)d->map[reg->pc + 2]]) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		//param = find_hexa();
		(pc = reg->pc + 4) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		r = d->map[pc] - 1;
		//if (r >= 0 && r <= 16)
		//	ft_memcpy(reg->r[r], param, 2);
		jump_to_next(d, reg, 5, false);
		reg->carry = 1;
		reg->cycle = 0;
	}
}
