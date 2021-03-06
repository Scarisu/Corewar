/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:06:53 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/11 21:36:46 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** read(0, e->champ.buff, 1);
*/

void	clean(t_asm *e)
{
	ft_memdel((void **)&e->bin.head);
	ft_memdel((void **)&e->bin.file);
	ft_memdel((void **)&e->champ.file_name);
	ft_memdel((void **)&e->champ.file_path);
	ft_memdel((void **)&e->champ.line);
	ft_memdel((void **)&e->champ.valid.name);
	ft_memdel((void **)&e->champ.valid.comment);
	ft_memdel((void **)&e->verbos.cmd_invalid);
	ft_memdel((void **)&e->verbos.opcode_name);
	clean_label(e->champ.valid.label_start);
	clean_frag(e->verbos.frag_start);
	clean_enco(e->enco_start);
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

void	clean_enco(t_enco *e)
{
	int		i;
	t_enco	*prev;

	while ((prev = e))
	{
		i = -1;
		while (++i < MAX_ARGS_NUMBER - 1)
			clean_label(e->arg[i].arg_label);
		e = e->next;
		ft_memdel((void **)&prev);
	}
}
