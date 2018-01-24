/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:52 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/24 11:52:29 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_ld(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		r;
	int		pc;
	char	param[2];

	(void)champs;
	if (++reg->cycle == 5)
	{
		(pc = reg->pc + 2) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		param[0] = d->map[pc];
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		param[1] = d->map[pc];
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		r = d->map[pc];
		if (r >= 0 && r <= 16)
			ft_memcpy(reg->r[r], param, 2);
		jump_to_next(d, reg, 5);
		reg->carry = 1;
		reg->cycle = 0;
	}
}
