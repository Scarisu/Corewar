/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:48 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/06 01:01:14 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_reg	*fork_reg(t_reg *reg)
{
	t_reg	*ret;

	ret = ft_memalloc(sizeof(t_reg));
	ret->n = reg->n;
	ret->pc = reg->pc;
	ret->cycle = reg->cycle;
	ret->carry = reg->carry;
	ft_memcpy(ret->r, reg->r, sizeof(unsigned char) * REG_NUMBER * REG_SIZE);
	ret->prev = reg;
	ret->next = NULL;
	return (ret);
}

void	op_fork(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		pc;

	(void)champs;
	if (++reg->cycle == 10)
	{
		reg->cycle = 0;
		pc = find_hexa(d->map, reg->pc + 1, 2);
		reg->next = fork_reg(reg);
		jump_to_next(d, reg->next, pc % IDX_MOD, true);
		jump_to_next(d, reg, 3, false);
	}
}
