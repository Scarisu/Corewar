/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:48 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/28 07:43:31 by rlecart          ###   ########.fr       */
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
	ret->live_counter = reg->live_counter;;
	ft_memcpy(ret->r, reg->r, sizeof(int) * REG_NUMBER);
	while (reg && reg->prev)
		reg = reg->prev;
	if (reg->next)
	{
		reg->prev = ret;
		ret->next = reg;
	}
	else
		ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void	op_fork(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		pc;
	t_reg	*tmp;

	(void)champs;
	if (++reg->cycle == 800 && !(reg->cycle = 0))
	{
		tmp = reg;
		pc = find_hexa(d->map, reg->pc + 1, 2);
		reg = fork_reg(reg);
		jump_to_next(d, reg, pc % IDX_MOD, true);
		jump_to_next(d, tmp, 3, false);
	}
}
