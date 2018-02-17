/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:34 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/17 02:12:00 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_sub(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		i;
	int		pc;
	int		r[3];

	(void)champs;
	if (++reg->cycle == 10)
	{
		i = -1;
		(pc = reg->pc + 2) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		r[0] = d->map[pc] - 1;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		r[1] = d->map[pc] - 1;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		r[2] = d->map[pc] - 1;
		reg->r[r[2]] = reg->r[r[0]] - reg->r[r[1]];
		jump_to_next(d, reg, 5, false);
		reg->carry = !reg->r[r[2]] ? 1 : 0;
		reg->cycle = 0;
		//printw("r%d = %d\n", r[0], reg->r[r[0]]);
		//printw("r%d = %d\n", r[1], reg->r[r[1]]);
		//printw("r%d = %d\n", r[2], reg->r[r[2]]);
		//refresh();
		//while (1);
	}
}
