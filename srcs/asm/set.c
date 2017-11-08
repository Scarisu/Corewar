/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:34:13 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/08 22:45:37 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	set_data(t_asm *e)
{
	e->champ.fd = -1;
	e->champ.file_path = NULL;
	e->champ.file_name = NULL;
	e->champ.line = NULL;
	if (!(e->champ.all = ft_strnew(0)))
		error(e, MALLOC);
	e->champ.valid.name = NULL;
	e->champ.valid.comment = NULL;
	e->champ.valid.prev = NULL;
	e->verbos.nb_error = 0;
	e->verbos.nb_line = 1;
	I = 0;
	e->verbos.sw = 1;
	e->verbos.len_arrow = 0;
}

void	set_ptr(t_verbos *v)
{
	v->tab[NAME_EXIST] = name_exist;
	v->tab[SYNTAX] = syntax;
	v->tab[INVALID_NAME] = invalid_name;
	v->tab[NAME_DIFF_FILE] = name_diff_file;
	v->tab[INVALID_CHAR] = invalid_char;
	v->tab[COMMENT_EXIST] = comment_exist;
}
