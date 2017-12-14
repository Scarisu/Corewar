/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 03:02:56 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/28 20:43:22 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	invalid_label(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.label->name)) > 30)
		e->verbos.len_arrow = 30;
	ft_memdel((void **)&e->champ.valid.label->name);
	add_cont(e, &V_LINE, WHITE "Label can't be null and ");
	add_cont(e, &V_LINE, "must only contain {" GREY LABEL_CHARS WHITE "}");
}

void	label_multi_init(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->verbos.pars->name)) > 30)
		e->verbos.len_arrow = 30;
	add_cont(e, &V_LINE, WHITE "Label \"" GREY);
	add_cont(e, &V_LINE, e->verbos.pars->name);
	ft_memdel((void **)&e->verbos.pars->name);
	add_cont(e, &V_LINE, WHITE "\" already initialized");
}

void	label_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->enco->arg_label->name)) > 30)
		e->verbos.len_arrow = 30;
	else if (e->enco->arg_label->type == T_DIR)
		++e->verbos.len_arrow;
	add_cont(e, &V_LINE, WHITE "Label \"" GREY);
	add_cont(e, &V_LINE, e->enco->arg_label->name);
	add_cont(e, &V_LINE, WHITE "\" isn't initialized");
}

void	label_used(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.label->name)) > 30)
		e->verbos.len_arrow = 30;
	add_cont(e, &V_LINE, WHITE "Label \"" GREY);
	add_cont(e, &V_LINE, e->champ.valid.label->name);
	add_cont(e, &V_LINE, WHITE "\" hasn't been used");
}
