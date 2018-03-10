/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:34 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/10 08:22:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	say_something(int value, t_corewar *d, t_reg *reg)
{
	char	c;

	c = value % 256;
	ft_putstr("(");
	display_champs_color(reg->n);
	ft_putstr(d->champs[reg->n - 1].name);
	display_champs_color(0);
	ft_putstr(") lance \"");
	display_champs_color(reg->n);
	ft_putchar(c);
	display_champs_color(0);
	ft_putstr("\", ");
	if (c % 2)
		ft_putstr("c'est tres efficace !\n");
	else
		ft_putstr("ce n'est pas tres efficace !\n");
}

void	op_aff(t_corewar *d, t_reg *reg)
{
	int		r;
	int		pc;
	t_ocp	ocp;

	if (++reg->cycle == 2 && !(reg->cycle = 0))
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[pc])) && (false_command(d, reg, true)))
			return ;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if ((r = find_hexa(d->map, pc, 1)) >= 1 && r <= 16)
			say_something(reg->r[r - 1], d, reg);
		jump_to_next(d, reg, 2, false);
	}
}
