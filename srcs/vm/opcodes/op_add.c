/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:24 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/06 01:16:48 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_add(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int				i;
	int				r[3];
	int				pc;
	unsigned char	param[4];

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
		while (++i < 4)
			if ((int)(reg->r[r[0]][i] + reg->r[r[1]][i]) > UCHAR_MAX)
				param[i] = 0;
			else
				param[i] = reg->r[r[0]][i] + reg->r[r[1]][i];
		ft_memcpy(reg->r[r[2]], param, 4);
		jump_to_next(d, reg, 5, false);
		reg->carry = 1;
		reg->cycle = 0;
	}
}
