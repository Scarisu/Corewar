/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:15:11 by rlecart           #+#    #+#             */
/*   Updated: 2017/11/23 10:03:58 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_champ		*get_all_champs(char **argv)
{
	int			i;
	int			nbc;
	t_champ		*champs;

	i = -1;
	nbc = ft_atoi(argv[0]);
	champs = ft_memalloc(nbc * sizeof(t_champ));
	while (++i < nbc)
	{
		champs[i].content = ft_ttoa(ft_get_file(argv[1 + i]));
		champs[i].len = ft_strlen(champs[i].content);
		champs[i].alive = 1;
		// name et comment va falloir parser mon con :)
	}
	return (champs);
}
