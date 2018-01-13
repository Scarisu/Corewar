/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:15:05 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/13 04:07:50 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	game(char *map)
{
	(void)map;
}

void	end_game(t_champ *champs, t_corewar *d)
{
	int		i;

	i = 0;
	while (champs[i].alive == false)
		i++;
	if (i >= d->nbc)
		error(-1, "haha");
	if (d->flag_v)
	{
		printw("Le joueur %d(%s) a gagne.\n\n", i + 1, champs[i].name);
		printw("Appuyez sur une touche pour continuer.");
	}
	else
	{
		ft_putstr("Le joueur ");
		ft_putnbr(i + 1);
		ft_putstr("(");
		ft_putstr(champs[i].name);
		ft_putstr(") a gagne.\n");
	}
}
