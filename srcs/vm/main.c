/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/14 02:10:21 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		main(int argc, char **argv)
{
	int			nbc;
	t_champ		*champs;

	if (argc <= 1)
		usage();
	nbc = get_nbc(argv + 1);
	champs = get_all_champs(argv + 1, nbc);
	battle(champs, nbc);
	return (0);
}
