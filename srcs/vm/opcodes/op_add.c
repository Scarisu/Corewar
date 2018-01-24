/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:24 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/24 14:15:49 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_add(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int				i;
	int				r1;
	int				r2;
	int				r3;
	int				pc;
	unsigned char	param[4];

	(void)champs;
	if (++reg->cycle == 10)
	{
		i = -1;
		(pc = reg->pc + 2) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		r1 = d->map[pc] - 1;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		r2 = d->map[pc] - 1;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		r3 = d->map[pc] - 1;
		while (++i < 4)
		{
			if ((int)(reg->r[r1][i] + reg->r[r2][i]) > UCHAR_MAX)
				param[i] = 0;
			else
				param[i] = reg->r[r1][i] + reg->r[r2][i];
		}
		ft_memcpy(reg->r[r3], param, 4);
		printw("add :\n\n");
		printw("%d : %d %d %d %d\n", r1, reg->r[r1][0], reg->r[r1][1], reg->r[r1][2], reg->r[r1][3]);
		printw("%d : %d %d %d %d\n", r2, reg->r[r2][0], reg->r[r2][1], reg->r[r2][2], reg->r[r2][3]);
		printw("%d : %d %d %d %d\n", r3, reg->r[r3][0], reg->r[r3][1], reg->r[r3][2], reg->r[r3][3]);
		refresh();
//		sleep(1);
		jump_to_next(d, reg, 5);
		reg->carry = 1;
		reg->cycle = 0;
	}
}
