/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:12:46 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/20 09:02:03 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	display_map(char *map, t_corewar *d)
{
	int		i;

	i = -1;
	system("clear");
	ft_putstr("Cycle : ");
	ft_putnbr(d->cycle);
	ft_putstr(" | Cycle to die : ");
	ft_putnbr(d->cycle_to_die);
	ft_putstr(" | Cycle delta : ");
	ft_putnbr(d->cycle_delta);
	ft_putstr(" | Max checks : ");
	ft_putnbr(d->max_checks);
	ft_putstr("\n\n");
	while (++i < MEM_SIZE)
	{
		if (map[i] >= 0 && map[i] < 16)
			ft_putchar('0');
		if (map[i] < 0)
			ft_putstr(ft_itoa_base(256 + map[i], 16, "0123456789abcdef"));
		else
			ft_putstr(ft_itoa_base(map[i], 16, "0123456789abcdef"));
		if ((i + 1) % ft_sqrt(MEM_SIZE))
			ft_putchar(' ');
		else
			ft_putchar('\n');
	}
	ft_putchar('\n');
}

int		still_alive(t_champ *champs, int nbc)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < nbc)
		if (champs[i].alive == true)
			count++;
	return (count > 1 ? 1 : 0);
}

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
	d->cycle_to_die = CYCLE_TO_DIE;
	d->cycle_delta = CYCLE_DELTA;
	d->nbr_live = 0;
	d->max_checks = MAX_CHECKS;
	return (map);
}

void	game(char *map)
{
	(void)map;
}

void	end_game(char *map, t_champ *champs, t_corewar *d)
{
	(void)map;
	(void)champs;
	(void)d;
}

void	battle(t_champ *champs, t_corewar *d)
{
	char	*map;

	map = init_battle(champs, d);
	while (d->cycle_to_die > 0)
	{
		if (d->dump >= 0 && d->cycle == d->dump)
		{
			display_map(map, d);
			exit(0);
		}
		d->cycle += 20;
		d->cycle_tmp += 20;
		if (d->cycle_tmp >= d->cycle_to_die)
		{
			if (d->nbr_live == NBR_LIVE)
				d->cycle_to_die -= d->cycle_delta;
			if (!still_alive(champs, d->nbc))
				end_game(map, champs, d);
			d->cycle_tmp = 0;
		}
		game(map);
		display_map(map, d);
	}
}
