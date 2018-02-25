/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 04:14:13 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/25 19:31:57 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	put_hexa(t_corewar *d, int nbc, int pc, int value)
{
	int		i;
	int		len;

	i = -1;
	len = 4;
	while (pc >= MEM_SIZE || pc < 0)
	{
		if (pc >= MEM_SIZE)
			pc -= MEM_SIZE;
		else
			pc += MEM_SIZE;
	}
	while (++i < len)
	{
		d->map[i] = value >> 8 * (len - i - 1);
		d->colors[pc] = nbc;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
	}
	//printw("pc = %d\n", pc);
	//refresh();
	//while (1);
}
