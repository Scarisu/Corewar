/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2018/01/12 03:04:23 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		main(int argc, char **argv)
{
	t_champ		*champs;
	t_corewar	data;

	initscr();						/* Start curses mode */
	//raw();
	keypad(stdscr, TRUE);
	noecho();
	data = check_all(argc - 1, argv + 1);
	champs = get_all_champs(data);
	battle(champs, &data);
	while (1);
	endwin();						/* End curses mode  */
	return (0);
}
