/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:27 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/23 01:47:45 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_st(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		r;
	int		i;
	int		pc;
	char	param[2];

	(void)champs;
	r = -1;
	if (++reg->cycle == 5)
	{
		i = -1;
		pc = reg->pc;
		while (++i < 4)
		{
			pc++;
			if (pc > MEM_SIZE)
				pc = 0;
			if (i == 1)
				r = d->map[pc];
			if (i > 1)
				param[i - 2] = d->map[pc];
		}
		if (r >= 0 && r <= 16)
			ft_memcpy(reg->r[r], param, 2);
		jump_to_next(d, reg, 5);
		reg->cycle = 0;
	}
}
