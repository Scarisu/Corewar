/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/01 04:00:30 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		main(int argc, char **argv)
{
	t_asm	e;

	init_all(&e);
	usage(&e, argc, argv);
	check_line(&e, &e.verbos, &e.champ);
	if (!print_verbos(&e.verbos))
		create_cor(&e);
	clean(&e);
	return (0);
}

void	init_all(t_asm *e)
{
	e->flag = 0;
	set_champ(e, &e->champ);
	set_verbos(e, &e->verbos);
	set_bin(e, &e->bin);
	e->enco = set_enco(e);
	e->enco_start = e->enco;
	set_ptrft(e);
}
