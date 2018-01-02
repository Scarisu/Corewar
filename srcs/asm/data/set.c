/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:34:13 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/12 00:32:06 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	set_champ(t_asm *e, t_champ *c)
{
	c->fd = -1;
	c->file_path = NULL;
	c->file_name = NULL;
	c->line = NULL;
	c->valid.name_done = 0;
	c->valid.comment_done = 0;
	c->valid.name = NULL;
	c->valid.comment = NULL;
	c->valid.label = set_label(e, (int[2]){0, 0});
	c->valid.label_start = e->champ.valid.label;
}

void	set_verbos(t_asm *e, t_verbos *v)
{
	v->nb_error = 0;
	v->nb_warning = 0;
	v->nb_line = 1;
	v->i = 0;
	v->len_arrow = 0;
	v->cmd_invalid = NULL;
	v->opcode_name = NULL;
	v->pars = NULL;
	v->prev_pars = NULL;
	v->frag = set_frag(e, (int[2]){0, 0});
	v->frag_start = e->verbos.frag;
	set_ptrver(v);
}

void	set_ptrver(t_verbos *v)
{
	v->tab[NAME_EXIST] = name_exist;
	v->tab[SYNTAX] = syntax;
	v->tab[NAME_LEN] = name_len;
	v->tab[INVALID_CHAR] = invalid_char;
	v->tab[COMMENT_EXIST] = comment_exist;
	v->tab[COMMENT_LEN] = comment_len;
	v->tab[INVALID_COMMANDE] = invalid_command;
	v->tab[INVALID_LABEL] = invalid_label;
	v->tab[OPCODE_EXIST] = opcode_exist;
	v->tab[MISSING_NAME] = missing_name;
	v->tab[MISSING_COMMENT] = missing_comment;
	v->tab[NEED_ARG] = need_arg;
	v->tab[WRONG_ARG] = wrong_arg;
	v->tab[TOO_MANY_ARG] = too_many_arg;
	v->tab[INVALID_REG] = invalid_reg;
	v->tab[INVALID_DIR_VAL] = invalid_dir_val;
	v->tab[INVALID_IND_VAL] = invalid_ind_val;
	v->tab[INVALID_LABEL_ARG] = invalid_label_arg;
	v->tab[LABEL_USED] = label_used;
	v->tab[LABEL_MULTI_INIT] = label_multi_init;
	v->tab[LABEL_EXIST] = label_exist;
}

void	set_bin(t_asm *e, t_bin *b)
{
	if (!(b->head = (int *)malloc(sizeof(int))))
		error(e, MALLOC);
	b->len_head = 0;
	if (!(b->file = (int *)malloc(sizeof(int))))
		error(e, MALLOC);
	b->len_file = 0;
	b->op_pos = 1;
}

void	set_ptrft(t_asm *e)
{
	e->tab[0] = skip_tab;
	e->tab[1] = cmd_name;
	e->tab[2] = cmd_comment;
	e->tab[3] = cmd_check;
	e->tab[4] = ins_label;
	e->tab[5] = ins_opcode;
}
