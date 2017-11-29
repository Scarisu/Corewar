/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:06:53 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/23 05:58:47 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	clean(t_asm *e)
{
	ft_memdel((void **)&e->head);
	ft_memdel((void **)&e->file);
	ft_memdel((void **)&e->champ.file_name);
	ft_memdel((void **)&e->champ.line);
	ft_memdel((void **)&e->champ.valid.name);
	ft_memdel((void **)&e->champ.valid.comment);
	ft_memdel((void **)&e->verbos.cmd_invalid);
	ft_memdel((void **)&e->verbos.opcode_name);
	clean_label(e->champ.valid.label_start);
	clean_label(e->champ.valid.check_start);
	clean_frag(e->verbos.frag_start);
	read(0, e->champ.buff, 1);
}

void	clean_label(t_label *l)
{
	t_label *prev;

	while ((prev = l))
	{
		ft_memdel((void **)&l->name);
		ft_memdel((void **)&l->line);
		l = l->next;
		ft_memdel((void **)&prev);
	}
}

void	clean_frag(t_frag *f)
{
	t_frag *prev;

	while ((prev = f))
	{
		ft_memdel((void **)&f->print);
		f = f->next;
		ft_memdel((void **)&prev);
	}
}
