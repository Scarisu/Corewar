/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:07 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/29 11:30:59 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	im_alive(t_corewar *d, t_champ *champs, t_reg *reg)
{
	attron(COLOR_PAIR(d->colors[reg->pc] - 5));
	printw("%s", champs->name);
	attroff(COLOR_PAIR(d->colors[reg->pc] - 5));
	printw(": IM ALIIIVE\n", reg->n);
	refresh();
	//sleep(1);
}

void	op_live(t_corewar *d, t_reg *reg)
{
	int		pc;
	int		param;

	if (++reg->cycle == 10 && !(reg->cycle = 0))
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if ((param = find_hexa(d->map, pc, 4)) >= 1 && param <= 4)
		{
			if (d->flag_v)
				im_alive(d, d->champs, reg);
			reg->live_counter++;
			d->last_live_call = param;
			d->champs[param - 1].nbr_live++;
			jump_to_next(d, reg, 5, false);
		}
		else
			jump_to_next(d, reg, 1, false);
	}
}
