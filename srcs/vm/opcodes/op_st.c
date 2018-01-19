/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:27 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/19 16:15:13 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_st(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		r;
	int		i[2];
	char	param[2];

	(void)champs;
	r = -1;
	if (++reg->cycle == 5)
	{
		i[0] = -1;
		i[1] = reg->pc;
		while (++i[0] < 4)
		{
			i[1]++;
			if (i[1] > MEM_SIZE)
				i[1] = 0;
			if (i[0] == 1)
				r = d->map[i[1]];
			if (i[0] > 1)
				param[i[0] - 2] = d->map[i[1]];
		}
		if (r >= 0 && r <= 16)
			ft_memcpy(reg->r[r], param, 2);
		jump_to_next(d, reg, 5);
		reg->cycle = 0;
	}
}
