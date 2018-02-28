/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:07 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/28 07:24:02 by rlecart          ###   ########.fr       */
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

void	op_live(t_champ *champs, t_corewar *d, t_reg *reg)
{
	if (++reg->cycle == 10 && !(reg->cycle = 0))
	{
		if (d->flag_v)
			im_alive(d, champs, reg);
		jump_to_next(d, reg, 5, false);
		reg->live_counter++;
		champs->nbr_live++;
		d->last_live_call = reg->n;
	}
}
