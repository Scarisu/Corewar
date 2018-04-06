/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 23:21:30 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/06 23:23:07 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

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
