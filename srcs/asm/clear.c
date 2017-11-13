/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:06:53 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/13 23:51:33 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	clean(t_asm *e)
{
	ft_memdel((void **)&e->champ.file_name);
	ft_memdel((void **)&e->champ.line);
	ft_memdel((void **)&e->champ.all);
	ft_memdel((void **)&e->champ.valid.name);
	ft_memdel((void **)&e->champ.valid.comment);
	ft_memdel((void **)&e->champ.valid.prev);
	ft_memdel((void **)&e->verbos.cmd_invalid);
	clean_label(e->champ.valid.label_start);
	clean_label(e->champ.valid.check_start);
	read(0, e->champ.buff, 1);
}

void clean_label(t_label *l)
{
	t_label *prev;

	while ((prev = l))
	{
		ft_memdel((void **)&l->name);
		l = l->next;
		ft_memdel((void **)&prev);
	}
}
