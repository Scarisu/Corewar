/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:56:01 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/05 21:51:42 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	name_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(NAME_CMD_STRING) - 1) > 30)
		e->verbos.len_arrow = 30;
	add_cont(e, &V_LINE, WHITE "Champion's name already set");
	if ((e->champ.valid.name))
	{
		add_cont(e, &V_LINE, ": \"" GREY);
		add_cont(e, &V_LINE, e->champ.valid.name);
		add_cont(e, &V_LINE, WHITE "\"");
	}
}

void	name_len(t_asm *e)
{
	int		start;
	char	*nbr;

	start = 0;
	nbr = NULL;
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.name) + 1) > 30)
		e->verbos.len_arrow = 30;
	add_cont(e, &V_LINE, WHITE "Champion's name too long {" GREY);
	if (!(nbr = ft_itoa(ft_strlen(e->champ.valid.name))))
		error(e, MALLOC);
	ft_memdel((void **)&e->champ.valid.name);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
	add_cont(e, &V_LINE, WHITE "}, max name len: {" GREY);
	if (!(nbr = ft_itoa(PROG_NAME_LENGTH)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
	add_cont(e, &V_LINE, WHITE "}");
}

/*
** void	syntax(t_asm *e);
*/

/*
** void	invalid_char(t_asm *e);
*/
