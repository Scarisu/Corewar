/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:12:46 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/12 03:00:50 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

char	*init_battle(t_champ *champs, t_corewar *d)
{
	int		i;
	char	*map;

	i = -1;
	map = ft_memalloc(MEM_SIZE);
	while (++i < d->nbc)
		ft_memcpy(&map[MEM_SIZE / d->nbc * i], champs[i].content, champs[i].len);
	d->cycle = 0;
	d->cycle_tmp = 0;
	d->nbr_live_all = 0;
	d->cycle_to_die = CYCLE_TO_DIE;
	d->cycle_delta = CYCLE_DELTA;
	d->max_checks = MAX_CHECKS;
	return (map);
}

void	battle(t_champ *champs, t_corewar *d)
{
	char	*map;

	map = init_battle(champs, d);
	while (d->cycle_to_die > 0)
	{
		if ((d->dump >= 0 && d->cycle == d->dump) ||
			(d->cycle_tmp + 1 >= d->cycle_to_die &&
			 d->cycle_to_die - d->cycle_delta <= 0))
		{
			display_map(map, d, 2);
			break ;
		}
		d->cycle += 20;
		d->cycle_tmp += 20;
		d->nbr_live_all = live_counter(champs, d);
		if (d->cycle_tmp >= d->cycle_to_die)
		{
			if (d->nbr_live_all >= NBR_LIVE)
				d->cycle_to_die -= d->cycle_delta;
			d->cycle_tmp = 0;
			if (--d->max_checks == 0)
			{
				d->cycle_to_die -= d->cycle_delta;
				d->max_checks = MAX_CHECKS;
			}
			reset_lives(champs, d->nbc);
		}
		game(map);
		if (d->dump == -1)
			display_map(map, d, 1);
		if (d->cycle % 2650)
			champs[0].nbr_live++;
	}
	end_game(champs, d->nbc);
}
