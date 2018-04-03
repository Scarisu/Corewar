/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:12:46 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 12:01:36 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	foam_bat(void)
{
}

void	delete_process(t_reg *t, t_reg *next, t_champ *champs, int i)
{
	if (!t->next && !t->prev)
	{
		champs[i].is_alive = false;
		ft_memdel((void**)&champs[i].reg);
	}
	else
	{
		if (t->prev)
			t->prev->next = t->next;
		if (t->next)
			t->next->prev = t->prev;
	}
	if (next)
		champs[i].reg = get_first_reg(next);
	else if ((champs[i].reg = get_first_reg(t)) == t)
		champs[i].reg = NULL;
	ft_memdel((void**)&t);
	foam_bat();
}

void	process_killer(t_champ *champs, t_corewar *d)
{
	int		i;
	t_reg	*t;
	t_reg	*next;

	i = d->nbc;
	while (--i >= 0)
	{
		t = champs[i].reg;
		while (t)
		{
			next = t->next;
			if (t->live_counter <= 0)
				delete_process(t, next, champs, i);
			else
				t->live_counter = 0;
			t = next;
		}
	}
}

int		cycle_check(t_champ *champs, t_corewar *d)
{
	if (!(d->cycle_tmp % d->cycle_to_die))
	{
		process_killer(champs, d);
		if (d->nbr_live_all >= NBR_LIVE && (d->max_checks = MAX_CHECKS + 1))
			d->cycle_to_die -= d->cycle_delta;
		d->cycle_tmp = 0;
		if (--d->max_checks == 0)
		{
			d->cycle_to_die -= d->cycle_delta;
			d->max_checks = MAX_CHECKS;
		}
		reset_lives(champs, d->nbc);
	}
	if (d->cycle_to_die < 0)
		return (0);
	else
		return (1);
}

void	battle(t_champ *champs, t_corewar *d)
{
	d->map = init_battle(champs, d);
	d->colors = init_colors(champs, d);
	while (d->cycle_to_die > 0 && still_alive(champs, d->nbc))
	{
		if ((d->dump >= 0 && d->cycle == d->dump))
		{
			display_map(d->map, d->colors, d);
			break ;
		}
		d->cycle += 1;
		d->cycle_tmp += 1;
		d->nbr_live_all = live_counter(champs, d);
		if (!(cycle_check(champs, d)))
			break ;
		game(champs, d, d->map);
		if (d->dump == -1)
			display_map(d->map, d->colors, d);
	}
	end_game(champs, d);
}
