/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/09 01:21:50 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		main(int argc, char **argv)
{
	t_asm	e;

	set_data(&e);
	set_ptrft(&e);
	usage(&e, argc, argv[1]);
	check_line(&e);
	e.verbos.nb_error ? nb_error(&e) : printf("[TADA]\n");
	clean(&e);
	return (0);
}

void	nb_error(t_asm *e)
{
	if ((e->verbos.line_left))
		ft_putstr_fd("Minimun ", 2);
	ft_putnbr_fd(e->verbos.nb_error, 2);
	ft_putstr_fd(" error", 2);
	(e->verbos.nb_error > 1) ? ft_putchar_fd('s', 2) : 0;
	ft_putstr_fd(" generated.\n", 2);
}
