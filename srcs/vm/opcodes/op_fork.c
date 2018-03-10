/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:48 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/04 00:54:30 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_reg	*fork_reg(t_reg *reg, int pc, bool mod)
{
	t_reg	*ret;

	ret = ft_memalloc(sizeof(t_reg));
	ret->n = reg->n;
	if (mod)
		ret->pc = reg->pc + (pc % IDX_MOD);
	else
		ret->pc = reg->pc + pc;
	true_pc(&ret->pc);
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

void	op_fork(t_corewar *d, t_reg *reg)
{
	int		pc;
	t_reg	*tmp;

	if (++reg->cycle == 800 && !(reg->cycle = 0))
	{
		tmp = reg;
		pc = find_hexa(d->map, reg->pc + 1, 2);
		reg = fork_reg(reg, pc, true);
		jump_to_next(d, reg, 0, true);
		jump_to_next(d, tmp, 3, false);
	}
}
