/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:12:46 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/18 01:34:50 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	foam_bat(void)
{
	/* FOAM BAT SOUND */
}

void	champions_killer(t_champ *champs, t_corewar *d)
{
	int		i;

	i = -1;
	while (++i < d->nbc)
		if (!champs[i].nbr_live)
		{
			champs[i].alive = false;
			foam_bat();
		}
}

int		cycle_check(t_champ *champs, t_corewar *d)
{
	if (d->cycle_tmp >= d->cycle_to_die)
	{
		champions_killer(champs, d);
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
	while (d->cycle_to_die > 0/* && still_alive(champs, d->nbc)*/)
	{
		if ((d->dump >= 0 && d->cycle == d->dump))
		{
			display_map(d->map, d->colors, d);
			break ;
		}
		d->cycle += 1;
		d->cycle_tmp += 1;
		if (!(cycle_check(champs, d)))
			break ;
		game(champs, d, d->map);
		d->nbr_live_all = live_counter(champs, d);
		if (d->dump == -1)
			display_map(d->map, d->colors, d);
		/* A RETIRER */
		//usleep(100000);
		//sleep(1);
	}
	end_game(champs, d);
}
