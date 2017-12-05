/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:34:13 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/05 21:49:25 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	set_data(t_asm *e)
{
	if (!(e->head = ft_strnew(0)))
		error(e, MALLOC);
	if (!(e->file = ft_strnew(0)))
		error(e, MALLOC);
	e->size = 0;
	e->champ.fd = -1;
	e->champ.file_path = NULL;
	e->champ.file_name = NULL;
	e->champ.line = NULL;
	e->champ.valid.name_done = 0;
	e->champ.valid.comment_done = 0;
	e->champ.valid.name = NULL;
	e->champ.valid.comment = NULL;
	e->champ.valid.label = set_label(e, (int[2]){0, 0});
	e->champ.valid.label_start = e->champ.valid.label;
	e->champ.valid.check = set_label(e, (int[2]){0, 0});
	e->champ.valid.check_start = e->champ.valid.check;
	e->verbos.nb_error = 0;
	e->verbos.nb_warning = 0;
	e->verbos.nb_line = 1;
	I = 0;
	e->verbos.len_arrow = 0;
	e->verbos.cmd_invalid = NULL;
	e->verbos.opcode_name = NULL;
	e->verbos.pars = NULL;
	e->verbos.prev_pars = NULL;
	e->verbos.frag = set_frag(e, (int[2]){0, 0});
	e->verbos.frag_start = e->verbos.frag;
}

void	set_ptrft(t_asm *e)
{
	e->tab[0] = skip_tab;
	e->tab[1] = cmd_name;
	e->tab[2] = cmd_comment;
	e->tab[3] = cmd_check;
	e->tab[4] = ins_label;
	e->tab[5] = ins_opcode;
	e->arg_value[0] = arg_reg_value;
	e->arg_value[1] = arg_dir_value;
	e->arg_value[2] = arg_ind_value;
}

void	set_ptrver(t_asm *e)
{
	e->verbos.tab[NAME_EXIST] = name_exist;
	e->verbos.tab[SYNTAX] = syntax;
	e->verbos.tab[NAME_LEN] = name_len;
	e->verbos.tab[INVALID_CHAR] = invalid_char;
	e->verbos.tab[COMMENT_EXIST] = comment_exist;
	e->verbos.tab[COMMENT_LEN] = comment_len;
	e->verbos.tab[INVALID_COMMANDE] = invalid_command;
	e->verbos.tab[INVALID_LABEL] = invalid_label;
	e->verbos.tab[INVALID_OPCODE] = invalid_opcode;
	e->verbos.tab[OPCODE_EXIST] = opcode_exist;
	e->verbos.tab[MISSING_NAME] = missing_name;
	e->verbos.tab[MISSING_COMMENT] = missing_comment;
	e->verbos.tab[NEED_ARG] = need_arg;
	e->verbos.tab[WRONG_ARG] = wrong_arg;
	e->verbos.tab[INVALID_REG] = invalid_reg;
	e->verbos.tab[NOT_ENOUGHT_ARG] = not_enought_arg;
	e->verbos.tab[INVALID_ARG_LABEL] = invalid_arg_label;
	e->verbos.tab[INVALID_DIR] = invalid_dir;
	e->verbos.tab[LABEL_MULTI_INIT] = label_multi_init;
}

t_label	*set_label(t_asm *e, int coo[2])
{
	t_label *new;

	if (!(new = (t_label *)malloc(sizeof(t_label))))
		error(e, MALLOC);
	ft_memcpy(new->coo, coo, sizeof(int[2]));
	new->octets = -1;
	new->name = NULL;
	new->line = NULL;
	new->next = NULL;
	return (new);
}

t_frag	*set_frag(t_asm *e, int coo[2])
{
	t_frag	*new;

	if (!(new = (t_frag *)malloc(sizeof(t_frag))))
		error(e, MALLOC);
	ft_memcpy(new->coo, coo, sizeof(int[2]));
	new->print = NULL;
	new->next = NULL;
	return (new);
}
