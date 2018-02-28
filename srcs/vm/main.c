/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2018/02/28 00:39:00 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	init_v(void)
{
	initscr();
	start_color();
	use_default_colors();
	init_color(8, 250, 250, 250);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, 8);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_YELLOW);
	init_pair(10, 8, COLOR_BLACK);
	keypad(stdscr, TRUE);
	noecho();
}

int		main(int argc, char **argv)
{
	t_champ		*champs;
	t_corewar	data;

	data = check_all(argc - 1, argv + 1);
	if (data.flag_v)
		init_v();
	champs = get_all_champs(data);
	battle(champs, &data);
	if (data.flag_v)
	{
		getch();
		endwin();
	}
	return (0);
}
