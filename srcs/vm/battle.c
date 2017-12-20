/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:12:46 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/20 07:16:01 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	display_map(char *map)
{
	int		i;

	i = -1;
	system("clear");
	while (++i < MEM_SIZE)
	{
		if (map[i] >= 0 && map[i] < 16)
			ft_putchar('0');
		if (map[i] < 0)
			ft_putstr(ft_itoa_base(256 + map[i], 16, "0123456789abcdef"));
		else
			ft_putstr(ft_itoa_base(map[i], 16, "0123456789abcdef"));
		if ((i + 1) % ft_sqrt(MEM_SIZE))
			ft_putchar(' ');
		else
			ft_putchar('\n');
	}
	ft_putchar('\n');
}

int		still_alive(t_champ *champs, int nbc)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < nbc)
		if (champs[i].alive == true)
			count++;
	return (count > 1 ? 1 : 0);
}

void	battle(t_champ *champs, t_corewar d)
{
	int		i;
	char	*map;

	i = -1;
	map = ft_memalloc(MEM_SIZE);
	while (++i < d.nbc)
		ft_memcpy(&map[MEM_SIZE / d.nbc * i], champs[i].content, champs[i].len);
	//while (still_alive(champs, d.nbc))
	//{
		display_map(map);
	//}
}
