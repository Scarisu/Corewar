/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:22:01 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/30 22:03:25 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		get_processes(int nbc, t_champ *champs)
{
	int		count;
	t_reg	*t;

	count = 0;
	while (--nbc >= 0)
	{
		t = champs[nbc].reg;
		while (t)
		{
			count++;
			t = t->next;
		}
	}
	return (count);
}

void	display_header(t_corewar *d)
{
	d->nbr_processes = get_processes(d->nbc, d->champs);
	if (d->flag_v)
	{
		printw("Cycle : %d | ", d->cycle);
		printw("Cycle to die : %d | ", d->cycle_to_die);
		printw("Cycle delta : %d | ", d->cycle_delta);
		printw("Max checks : %d | ", d->max_checks);
		printw("Lives : %d | ", d->nbr_live_all);
		printw("Processes : %d\n\n", d->nbr_processes);
	}
	else
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
}

void	display_v(char *map, int *colors, t_corewar *d)
{
	int		i;
	char	*tmp;

	i = -1;
	erase();
	display_header(d);
	while (++i < MEM_SIZE)
	{
		attron(COLOR_PAIR(colors[i]));
		if (map[i] >= 0 && map[i] < 16)
			printw("0");
		if (map[i] < 0)
			tmp = ft_itoa_base(256 + map[i], 16);
		else
			tmp = ft_itoa_base(map[i], 16);
		printw("%s", tmp);
		ft_strdel(&tmp);
		attroff(COLOR_PAIR(colors[i]));
		if ((i + 1) % (ft_sqrt(MEM_SIZE)))
			printw(" ");
		else
			printw("\n");
	}
	printw("\n");
	refresh();
}

void	display_champs_color(int color)
{
	if (color == 0)
		ft_putstr(C_RESET);
	else if (color == 1)
		ft_putstr(C_GREEN);
	else if (color == 2)
		ft_putstr(C_BLUE);
	else if (color == 3)
		ft_putstr(C_RED);
	else if (color == 4)
		ft_putstr(C_YELLOW);
	else
		ft_putstr(C_GREY);
}

void	display(char *map, int *colors, t_corewar *d)
{
	int		i;
	char	*tmp;

	i = -1;
	display_header(d);
	while (++i < MEM_SIZE)
	{
		display_champs_color(colors[i]);
		if (map[i] >= 0 && map[i] < 16)
			ft_putchar('0');
		if (map[i] < 0)
			tmp = ft_itoa_base(256 + map[i], 16);
		else
			tmp = ft_itoa_base(map[i], 16);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		display_champs_color(0);
		if ((i + 1) % (ft_sqrt(MEM_SIZE) / 2))
			ft_putchar(' ');
		else
			ft_putchar('\n');
		ft_putstr("");
	}
	ft_putchar('\n');
}

void	display_map(char *map, int *colors, t_corewar *d)
{
	if (d->flag_v && d->dump == -1)
		display_v(map, colors, d);
	else if (!d->flag_v && d->dump > 0)
		display(map, colors, d);
	ft_putstr(C_RESET);
}
