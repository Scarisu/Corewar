/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:48 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/30 22:18:15 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	print_reg(t_reg *reg)
{
	printw("%x %x %x %x\n", reg->r[0], reg->r[1], reg->r[2], reg->r[3]);
	printw("%x %x %x %x\n", reg->r[4], reg->r[5], reg->r[6], reg->r[7]);
	printw("%x %x %x %x\n", reg->r[8], reg->r[9], reg->r[10], reg->r[11]);
	printw("%x %x %x %x\n\n", reg->r[12], reg->r[13], reg->r[14], reg->r[15]);
}

t_reg	*fork_reg(t_reg *reg, int pc, bool mod)
{
	t_reg	*ret;

	ret = ft_memalloc(sizeof(t_reg));
	ret->n = reg->n;
	(void)pc;
	(void)mod;
	ret->pc = reg->pc;
	ret->cycle = reg->cycle;
	ret->carry = reg->carry;
	ret->live_counter = reg->live_counter;
	ft_memcpy(ret->r, reg->r, sizeof(int) * REG_NUMBER);
	ret->next = get_first_reg(reg);
	if (ret->next)
		ret->next->prev = ret;
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
		if ((pc = find_hexa(d->map, reg->pc + 1, 2)) > 65535 / 2)
			pc -= 65535;
		tmp = fork_reg(reg, pc, true);
		d->champs[reg->n - 1].reg = tmp;
		jump_to_next(d, reg, 3, true);
		jump_to_next(d, tmp, get_modulo(pc, IDX_MOD), false);
	}
}
