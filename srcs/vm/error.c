/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:25:10 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/17 22:47:44 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		display_error(char *str, char *var)
{
	ft_putstr_fd(str, 2);
	if (var)
	{
		ft_putstr_fd(" {", 2);
		ft_putstr_fd(var, 2);
		ft_putstr_fd("}", 2);
	}
	ft_putstr_fd("\n", 2);
	return (-1);
}

void	error(int code, char *var)
{
	code == 0 ? exit(display_error("usage: ./corewar [-v] [-dump nbr_cycles] [[-n number] champion1.cor] ...", var)) : 1;
	code == 1 ? exit(display_error("[Error] There is too much players.", var)) : 1;
	code == 2 ? exit(display_error("[Error] The name of the champion is too long.", var)) : 1;
	code == 3 ? exit(display_error("[Error] The comment of the champion is too long.", var)) : 1;
	code == 4 ? exit(display_error("[Error] The champion size is too long.", var)) : 1;
	code == 5 ? exit(display_error("[Error] The file doesn't exist.", var)) : 1;
	code < 0 || code > 5 ? exit(display_error("[Error] Undifined.", var)) : 1;
}
