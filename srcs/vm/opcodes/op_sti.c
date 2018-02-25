/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:31 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/25 19:45:14 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_sti(t_champ *champs, t_corewar *d, t_reg *reg)
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
			if (o.p[i] == O_REG)
				tmp = 1;
			else if (o.p[i] == O_DIR)
				tmp = 2;
			else if (o.p[i] == O_IND)
				tmp = 4;
			//tmp = o.p[i] == O_REG ? 1 : 4;
			//tmp = o.p[i] == O_DIR ? 2 : tmp;
			r[i] = find_hexa(d->map, pc, tmp);
			if (o.p[i] == O_REG && r[i] >= 1 && r[i] <= 16)
				r[i] = reg->r[r[i] - 1];
			else if (o.p[i] != O_REG && r[i] > 65536 / 2)
				r[i] -= 65536;
			(pc += tmp) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		}
		tmp = reg->pc + ((r[1] + r[2]) % IDX_MOD);
		while (tmp >= MEM_SIZE || tmp < 0)
		{
			if (tmp >= MEM_SIZE)
				tmp -= MEM_SIZE;
			else if (tmp < 0)
				tmp += MEM_SIZE;
		}
		put_hexa(d, reg->n, tmp, r[0]);
		jump_to_next(d, reg, pc - reg->pc, false);
		display_map(d->map, d->colors, d);
		//printw("r[0] = %d\n", r[0]);
		//printw("r[1] = %d\n", r[1]);
		//printw("r[2] = %d\n", r[2]);
		//printw("reg->r[3] = %d\n", reg->r[3]);
		//printw("tmp = %d\n", tmp);
		//refresh();
		while (1);
	}
}
//rdr
