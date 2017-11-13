/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:34:13 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/09 20:38:16 by pbernier         ###   ########.fr       */
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
	e->champ.valid.name_done = 0;
	e->champ.valid.comment_done = 0;
	e->champ.valid.name = NULL;
	e->champ.valid.comment = NULL;
	e->champ.valid.prev = NULL;
	e->verbos.nb_error = 0;
	e->verbos.nb_line = 1;
	I = 0;
	e->verbos.sw = 1;
	e->verbos.len_arrow = 0;
	e->verbos.cmd_invalid = NULL;
}

void	set_ptrft(t_asm *e)
{
	e->verbos.tab[NAME_EXIST] = name_exist;
	e->verbos.tab[SYNTAX] = syntax;
	e->verbos.tab[NAME_LEN] = name_len;
	e->verbos.tab[INVALID_NAME] = invalid_name;
	e->verbos.tab[NAME_DIFF_FILE] = name_diff_file;
	e->verbos.tab[INVALID_CHAR] = invalid_char;
	e->verbos.tab[COMMENT_EXIST] = comment_exist;
	e->verbos.tab[COMMENT_LEN] = comment_len;
	e->verbos.tab[INVALID_COMMANDE] = invalid_command;
	e->verbos.tab[MISSING_NAME] = missing_name;
	e->verbos.tab[MISSING_COMMENT] = missing_comment;
	e->tab[0] = skip_tab;
	e->tab[1] = cmd_name;
	e->tab[2] = cmd_comment;
	e->tab[3] = cmd_check;
}
