/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:15:05 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/13 02:36:40 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

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
	printw("Le joueur %d(%s) a gagne.\n\n", i + 1, champs[i].name);
	printw("Appuyez sur une touche pour continuer.");
}
