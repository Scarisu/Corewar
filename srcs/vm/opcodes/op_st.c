/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:27 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/24 14:44:58 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_st(t_champ *champs, t_corewar *d, t_reg *reg)
{
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
				memcpy(reg->r[r2], reg->r[r1], 2);
			jump_to_next(d, reg, 4);
		}
		else if (ocp.p[1] == O_IND)
		{
			(pc = reg->pc + 3) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			ind = d->map[reg->pc + 3];
			(pc = reg->pc + 4) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			ind += d->map[pc];
			(pc = reg->pc + (ind % IDX_MOD) + 1) >= MEM_SIZE ?
				pc -= MEM_SIZE : pc;
			ft_memcpy(&d->map[pc], reg->r[r1], 4);
			jump_to_next(d, reg, 5);
		}
		reg->cycle = 0;
	}
}
