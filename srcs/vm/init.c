/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 07:52:05 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/16 10:55:27 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

char	*init_battle(t_champ *champs, t_corewar *d)
{
	int		i;
	char	*map;

	i = -1;
	map = ft_memalloc(MEM_SIZE);
	while (++i < d->nbc)
	{
		ft_memcpy(&map[MEM_SIZE / d->nbc * i], champs[i].content, champs[i].len);
		REG = ft_memalloc(sizeof(t_reg));
		ft_bzero(REG->r, sizeof(REG->r));
		REG->r[0][REG_SIZE - 1] = i;
		REG->pc = &map[MEM_SIZE / d->nbc * i];
		REG->carry = 0;
		REG->prev = NULL;
		REG->next = NULL;
	}
	d->cycle = 0;
	d->cycle_tmp = 0;
	d->nbr_live_all = 0;
	d->cycle_to_die = CYCLE_TO_DIE;
	d->cycle_delta = CYCLE_DELTA;
	d->max_checks = MAX_CHECKS;
	d->last_live_call = 0;
	return (map);
}

int		*init_colors(t_champ *champs, t_corewar *d)
{
	int		i;
	int		j;
	int		*colors;

	i = -1;
	colors = ft_memalloc(MEM_SIZE * sizeof(int));
	ft_memset(colors, 5, MEM_SIZE * sizeof(int));
	while (++i < d->nbc && (j = -1))
		while (++j < champs[i].len)
			colors[MEM_SIZE / d->nbc * i + j] = i + 1;
	return (colors);
}
