/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 04:14:13 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/15 17:12:07 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	put_hexa(char *map, int pc, int value)
{
	int				i;
	int				len;
	unsigned char	tab[4];

	i = -1;
	len = 4;
	while (++i < len)
		tab[i] = value >> 8 * (len - i - 1);
	ft_memcpy(&map[pc], tab, 4);
	//printw("pc = %d\n", pc);
	//refresh();
	//while (1);
}
