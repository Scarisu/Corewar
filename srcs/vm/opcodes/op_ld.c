/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:52 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/23 06:01:03 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_ld(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		r;
	int		i[2];
	char	param[4];

	(void)champs;
	r = -1;
	if (++reg->cycle == 5)
	{
		i[0] = -1;
		i[1] = reg->pc;
		while (++i[0] < 6)
		{
			if (++i[1] > MEM_SIZE)
				i[1] = 0;
			if (i[0] == 5)
				r = d->map[i[1]];
			else
				param[i[0]] = d->map[i[1]];
		}
		if (r >= 0 && r <= 16)
			ft_memcpy(reg->r[r], param, 4);
		jump_to_next(d, reg, 5);
		reg->cycle = 0;
	}
}
