/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:22:01 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/13 02:37:45 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	display_map(char *map, t_corewar *d, int o)
{
	int		i;

	i = -1;
	erase();
	printw("Cycle : %d | ", d->cycle);
	printw("Cycle to die : %d | ", d->cycle_to_die);
	printw("Cycle delta : %d | ", d->cycle_delta);
	printw("Max checks : %d | ", d->max_checks);
	printw("Lives : %d\n\n", d->nbr_live_all);
	while (++i < MEM_SIZE)
	{
		if (map[i] >= 0 && map[i] < 16)
			printw("%c", '0');
		if (map[i] < 0)
			printw(ft_itoa_base(256 + map[i], 16, HEXA));
		else
			printw(ft_itoa_base(map[i], 16, HEXA));
		if ((i + 1) % (ft_sqrt(MEM_SIZE) / o))
			printw(" ");
		else
			printw("\n");
	}
	printw("\n");
	refresh();						/* Print it on to the real screen */
}
