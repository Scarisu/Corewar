/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:12:46 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/12 00:18:00 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	display_map(char *map, t_corewar *d, int o)
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
	ft_putstr(" | Lives : ");
	ft_putnbr(d->nbr_live_all);
	ft_putstr("\n\n");
	while (++i < MEM_SIZE)
	{
		if (map[i] >= 0 && map[i] < 16)
			ft_putchar('0');
		if (map[i] < 0)
			ft_putstr(ft_itoa_base(256 + map[i], 16, "0123456789abcdef"));
		else
			ft_putstr(ft_itoa_base(map[i], 16, "0123456789abcdef"));
		if ((i + 1) % (ft_sqrt(MEM_SIZE) / o))
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
	d->nbr_live_all = 0;
	d->cycle_to_die = CYCLE_TO_DIE;
	d->cycle_delta = CYCLE_DELTA;
	d->max_checks = MAX_CHECKS;
	return (map);
}

void	game(char *map)
{
	(void)map;
}

void	end_game(t_champ *champs, int nbc)
{
	int		i;

	i = 0;
	while (champs[i].alive == false)
		i++;
	if (i >= nbc)
		error(-1, "haha");
	ft_putstr("Le joueur ");
	ft_putnbr(i + 1);
	ft_putstr("(");
	ft_putstr(champs[i].name);
	ft_putstr(") a gagne.\n");
}

int		live_counter(t_champ *champs, t_corewar *d)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < d->nbc)
		count += champs[i].nbr_live;
	return (count);
}

void	reset_lives(t_champ *champs, int nbc)
{
	int		i;

	i = -1;
	while (++i < nbc)
		champs[i].nbr_live = 0;
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
		d->cycle += 1;
		d->cycle_tmp += 1;
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
