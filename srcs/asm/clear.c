/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:06:53 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/08 01:14:49 by pbernier         ###   ########.fr       */
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
	read(0, e->champ.buff, 1);
}
