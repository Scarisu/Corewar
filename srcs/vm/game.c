/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:15:05 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/12 02:15:33 by rlecart          ###   ########.fr       */
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
	ft_putstr("Le joueur ");
	ft_putnbr(i + 1);
	ft_putstr("(");
	ft_putstr(champs[i].name);
	ft_putstr(") a gagne.\n");
}
