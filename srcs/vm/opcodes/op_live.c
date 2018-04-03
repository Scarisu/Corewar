/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:07 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 13:04:56 by rlecart          ###   ########.fr       */
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
	//usleep(100000);
}

void	op_live(t_corewar *d, t_reg *reg)
{
	int		pc;
	int		param;

	if (++reg->cycle == 10 && !(reg->cycle = 0))
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		reg->live_counter++;
		if ((param = find_hexa(d->map, pc, 4)) >= 1 && param <= d->nbc)
		{
			if (d->flag_v)
				im_alive(d, d->champs, reg);
			d->last_live_call = param;
			d->champs[param - 1].nbr_live++;
		}
		jump_to_next(reg, 5);
	}
}
