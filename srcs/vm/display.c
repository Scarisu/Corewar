/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:22:01 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 11:56:15 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

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
	int		sq;

	i = -1;
	erase();
	display_header(d);
	sq = ft_sqrt(MEM_SIZE);
	while (++i < MEM_SIZE)
	{
		attron(COLOR_PAIR(colors[i]));
		printw("%02hhx", map[i]);
		attroff(COLOR_PAIR(colors[i]));
		if ((i + 1) % sq)
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
	int		sq;
	char	*tmp;

	i = -1;
	display_header(d);
	sq = ft_sqrt(MEM_SIZE) / 2;
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
		if ((i + 1) % sq)
			ft_putchar(' ');
		else
			ft_putchar('\n');
	}
	ft_putchar('\n');
}

int		get_color_here(t_corewar *d, int pc)
{
	int			i;
	int			ret;
	t_reg		*tmp;
	t_champ		*c;

	i = d->nbc;
	ret = 5;
	c = d->champs;
	while (--i >= 0)
	{
		tmp = c[i].reg;
		while (tmp)
		{
			if (tmp->pc == pc)
				ret = tmp->n;
			tmp = tmp->next;
		}
	}
	return (ret);
}

void	light_up_pc(t_corewar *d, int *colors)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if ((is_anybody_here(d, i)))
			colors[i] += 5;
	}
}

void	light_down(t_corewar *d, int *colors)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if ((is_anybody_here(d, i)))
			colors[i] -= 5;
	}
}

void	dis_oui(int *colors)
{
	int		i;
	int		sq;

	i = -1;
	sq = ft_sqrt(MEM_SIZE);
	erase();
	while (++i < MEM_SIZE)
	{
		attron(COLOR_PAIR(colors[i]));
		printw("%02hhd", colors[i]);
		attroff(COLOR_PAIR(colors[i]));
		if ((i + 1) % sq)
			printw(" ");
		else
			printw("\n");
	}
	refresh();
}

void	display_map(char *map, int *colors, t_corewar *d)
{
	light_up_pc(d, colors);
	if (d->flag_v && d->dump == -1)
		//dis_oui(colors);
		display_v(map, colors, d);
	else if (!d->flag_v && d->dump > 0)
		display(map, colors, d);
	ft_putstr(C_RESET);
	light_down(d, colors);
}
