/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/20 05:50:12 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		main(int argc, char **argv)
{
	t_champ		*champs;
	t_corewar	data;

	data = check_all(argc - 1, argv + 1);
	printf("data.nbc = %d\n", data.nbc);
	printf("data.dump = %d\n", data.dump);
	printf("data.numbers[0] = %d\n", data.numbers[0]);
	printf("data.numbers[1] = %d\n", data.numbers[1]);
	printf("data.numbers[2] = %d\n", data.numbers[2]);
	printf("data.numbers[3] = %d\n", data.numbers[3]);
	champs = get_all_champs(data);
	battle(champs, data);
	return (0);
}
