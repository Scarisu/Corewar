/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:27 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/13 04:17:01 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_st(t_champ *champs, t_corewar *d, t_reg *reg)
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
		r = d->map[pc];
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (ocp.p[1] == O_IND)
		{
			param = find_hexa(d->map, pc, 2);
			printw("%d\n", param);
			//printw("%d\n", r);
			//printw("%d\n", reg->r[r - 1]);
			refresh();
			while (1);
			put_hexa(d->map, reg->pc + param, reg->r[r - 1]);
		}
		else
		{
			param = d->map[pc];
			reg->r[param - 1] = reg->r[r - 1];
		}
		pc = ocp.p[1] == O_IND ? 3 : 4;
		jump_to_next(d, reg, pc, false);
		reg->cycle = 0;
	}
}
/*{
	int		r1;
	int		r2;
	int		ind;
	int		pc;
	t_ocp	ocp;

	(void)champs;
	if (++reg->cycle == 5)
	{
		(pc = reg->pc + 2) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		r1 = d->map[pc] - 1;
		if ((ocp = find_ocp(d->map[reg->pc + 1])).p[1] == O_REG)
		{
			(pc = reg->pc + 3) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			r2 = d->map[pc] - 1;
			if (r1 >= 0 && r1 <= 16 && r2 >= 0 && r2 <= 16)
			//	memcpy(reg->r[r2], reg->r[r1], 2);
			jump_to_next(d, reg, 4, false);
		}
		else if (ocp.p[1] == O_IND)
		{
			(pc = reg->pc + 3) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			ind = d->map[reg->pc + 3];
			(pc = reg->pc + 4) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			ind += d->map[pc];
			(pc = reg->pc + (ind % IDX_MOD) + 1) >= MEM_SIZE ?
				pc -= MEM_SIZE : pc;
			//ft_memcpy(&d->map[pc], reg->r[r1], 4);
			jump_to_next(d, reg, 5, false);
		}
		reg->cycle = 0;
	}
}*/
