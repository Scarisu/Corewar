/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:13:58 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/28 00:41:52 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		still_alive(t_champ *champs, int nbc)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < nbc)
		if (champs[i].reg)
			count++;
	return (count > 0 ? 1 : 0);
}

int		live_counter(t_champ *champs, t_corewar *d)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < d->nbc)
		count += champs[i].nbr_live;
	return (count);
}

void	reset_lives(t_champ *champs, int nbc)
{
	int		i;

	i = -1;
	while (++i < nbc)
		champs[i].nbr_live = 0;
}

