/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:27 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/17 04:04:11 by rlecart          ###   ########.fr       */
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
			if ((param = find_hexa(d->map, pc, 2)) > 65535 / 2)
				param -= 65535;
			//printw("param = %d\n", param);
			//printw("r = %d\n", r);
			//printw("r[%d] = %d\n", r, reg->r[r - 1]);
			//refresh();
			//while (1);
			put_hexa(d->map, reg->pc + param - 1, reg->r[r - 1]);
		}
		else
		{
			param = d->map[pc];
			reg->r[param - 1] = reg->r[r - 1];
		}
		pc = ocp.p[1] == O_IND ? 5 : 4;
		jump_to_next(d, reg, pc, false);
		reg->cycle = 0;
	}
}
