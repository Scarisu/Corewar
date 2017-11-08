/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/08 01:24:22 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		main(int argc, char **argv)
{
	t_asm	e;

	set_data(&e);
	set_ptr(&e.verbos);
	usage(&e, argc, argv[1]);
	check_line(&e, &e.champ.line);
	e.verbos.nb_error ? nb_error(e.verbos.nb_error) : printf("[TADA]\n");
	clean(&e);
	return (0);
}

void	nb_error(int nb_error)
{
	ft_putnbr_fd(nb_error, 2);
	ft_putstr_fd(" errors generated.\n", 2);
}
