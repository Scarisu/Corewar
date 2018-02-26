/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 04:14:13 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/27 00:17:53 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	true_pc(int *pc)
{
	while (*pc >= MEM_SIZE || *pc < 0)
	{
		if (*pc >= MEM_SIZE)
			*pc -= MEM_SIZE;
		else
			*pc += MEM_SIZE;
	}
}

void	put_hexa(t_corewar *d, int nbc, int pc, int value)
{
	int		i;
	int		len;

	i = -1;
	len = 4;
	true_pc(&pc);
	while (++i < len)
	{
		d->map[pc] = value >> 8 * (len - i - 1);
		d->colors[pc] = nbc;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
	}
}
