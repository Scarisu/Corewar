/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:34:13 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/13 23:52:49 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		set_data(t_asm *e)
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
	e->champ.valid.label = set_label(e, (int[2]){0, 0});
	e->champ.valid.label_start = e->champ.valid.label;
	e->champ.valid.check = set_label(e, (int[2]){0, 0});
	e->champ.valid.check_start = e->champ.valid.check;
	e->verbos.nb_error = 0;
	e->verbos.nb_line = 1;
	I = 0;
	e->verbos.len_arrow = 0;
	e->verbos.cmd_invalid = NULL;
}

void		set_ptrft(t_asm *e)
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
	e->verbos.tab[INVALID_LABEL] = invalid_label;
	e->verbos.tab[MISSING_NAME] = missing_name;
	e->verbos.tab[MISSING_COMMENT] = missing_comment;
	e->tab[0] = skip_tab;
	e->tab[1] = cmd_name;
	e->tab[2] = cmd_comment;
	e->tab[3] = cmd_check;
	e->tab[4] = ins_label;
}

t_label*	set_label(t_asm *e, int coo[2])
{
	t_label *new;

	if (!(new = (t_label *)malloc(sizeof(t_label))))
		error(e, MALLOC);
	ft_memcpy(new->coo, coo, sizeof(int[2]));
	new->name = NULL;
	new->next = NULL;
	return (new);
}
