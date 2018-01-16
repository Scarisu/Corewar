/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2018/01/16 11:01:59 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		main(int argc, char **argv)
{
	t_champ		*champs;
	t_corewar	data;

	data = check_all(argc - 1, argv + 1);
	if (data.flag_v)
	{
		initscr();						/* Start curses mode */
		start_color();/* Start color			*/
		use_default_colors();
		init_color(8, 250, 250, 250);
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_BLUE, COLOR_BLACK);
		init_pair(3, COLOR_RED, COLOR_BLACK);
		init_pair(4, COLOR_YELLOW, COLOR_BLACK);
		init_pair(5, COLOR_BLACK, 8);
		keypad(stdscr, TRUE);
		noecho();
	}
	champs = get_all_champs(data);
	battle(champs, &data);
	if (data.flag_v)
	{
		getch();
		endwin();						/* End curses mode  */
	}
	return (0);
}
