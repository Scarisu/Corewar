/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:25:10 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/19 10:14:28 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		display_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (-1);
}

void	error(int code)
{
	code == 0 ? exit(display_error("usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...")) : 1;
	code == 1 ? exit(display_error("[Error] There is too much players.")) : 1;
	code == 2 ? exit(display_error("[Error] The name of the champion is too long.")) : 1;
	code == 3 ? exit(display_error("[Error] The comment of the champion is too long.")) : 1;
	code == 4 ? exit(display_error("[Error] The champion size is too long.")) : 1;
	code != 0 && code != 1 && code != 2 && code != 3 && code != 4 ? exit(display_error("[Error] Undifined.")) : 1;
}
