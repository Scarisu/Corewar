/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 00:46:23 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/20 00:46:25 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_label	*set_label(t_asm *e, int coo[2])
{
	t_label *new;

	if (!(new = (t_label *)malloc(sizeof(t_label))))
		error(e, MALLOC);
	ft_memcpy(new->coo, coo, sizeof(int[2]));
	new->name = NULL;
	new->line = NULL;
	new->used = 0;
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

t_enco	*set_enco(t_asm *e)
{
	int		i;
	t_enco	*new;

	i = -1;
	if (!(new = (t_enco *)malloc(sizeof(t_enco))))
		error(e, MALLOC);
	new->opcode = 0;
	new->bin_arg = 0b00000000;
	while (++i < MAX_ARGS_NUMBER - 1)
	{
		new->arg[i].arg_value = 0;
		new->arg[i].arg_label = NULL;
		new->arg[i].type = 0;
	}
	new->nb_arg = 0;
	new->next = NULL;
	return (new);
}
