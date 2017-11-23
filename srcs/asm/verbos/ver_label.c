/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 03:02:56 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/23 07:51:58 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	invalid_label(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.label->name)) > 30)
		e->verbos.len_arrow = 30;
	ft_memdel((void **)&e->champ.valid.label->name);
	ft_putstr_fd(WHITE "Label can't be null and ", 2);
	ft_putstr_fd("must only contain {" GREY LABEL_CHARS WHITE "}", 2);
}

void	label_multi_init(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->verbos.pars->name)) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Label \"" GREY, 2);
	ft_putstr_fd(e->verbos.pars->name, 2);
	ft_memdel((void **)&e->verbos.pars->name);
	ft_putstr_fd(WHITE "\" already initialized", 2);
}
