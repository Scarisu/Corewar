/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:22:01 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/16 10:55:36 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	display_v(char *map, int *colors, t_corewar *d)
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
		attron(COLOR_PAIR(colors[i]));
		if (map[i] >= 0 && map[i] < 16)
			printw("%c", '0');
		if (map[i] < 0)
			printw(ft_itoa_base(256 + map[i], 16, HEXA));
		else
			printw(ft_itoa_base(map[i], 16, HEXA));
		if ((i + 1) % (ft_sqrt(MEM_SIZE)))
			printw(" ");
		else
			printw("\n");
		attroff(COLOR_PAIR(colors[i]));
	}
	printw("\n");
	refresh();						/* Print it on to the real screen */
}

void	display_header(t_corewar *d)
{
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
}

void	display(char *map, int *colors, t_corewar *d)
{
	int		i;
	char	*tmp;

	(void)colors;
	i = -1;
	display_header(d);
	while (++i < MEM_SIZE)
	{
		if (map[i] >= 0 && map[i] < 16)
			ft_putchar('0');
		if (map[i] < 0)
			tmp = ft_itoa_base(256 + map[i], 16, HEXA);
		else
			tmp = ft_itoa_base(map[i], 16, HEXA);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		if ((i + 1) % (ft_sqrt(MEM_SIZE) / 2))
			ft_putchar(' ');
		else
			ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	display_map(char *map, int *colors, t_corewar *d)
{
	if (d->flag_v)
		display_v(map, colors, d);
}
