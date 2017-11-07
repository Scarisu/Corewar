/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 20:00:11 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		main(int argc, char **argv)
{
	t_asm	e;

	set(&e);
	usage(&e, argc, argv[1]);
	check_line(&e, &e.champ.line);
//	!e.verbos.nb_error ? print_verbos() : create();
	clean(&e);
	return (0);
}
