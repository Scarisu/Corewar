/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:34:13 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 21:16:30 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	set(t_asm *e)
{
	e->champ.file_name = NULL;
	e->champ.line = NULL;
	if (!(e->champ.all = ft_strnew(0)))
		error(e, MALLOC);
	e->champ.valid.name = NULL;
	e->champ.valid.comment = NULL;
	e->champ.valid.prev = NULL;
	e->verbos.nb_error = 0;
	e->verbos.nb_line = 1;
	if (!(e->verbos.arrow = ft_strdup("^")))
		error(e, MALLOC);
}
