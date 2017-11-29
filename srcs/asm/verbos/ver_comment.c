/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:52:00 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/29 19:57:15 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	comment_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(COMMENT_CMD_STRING) - 1) > 30)
		e->verbos.len_arrow = 30;
	add_cont(e, &V_LINE, WHITE "Champion's description already set");
	if ((e->champ.valid.comment))
	{
		add_cont(e, &V_LINE, ": \"" GREY);
		add_cont(e, &V_LINE, e->champ.valid.comment);
		add_cont(e, &V_LINE, WHITE "\"");
	}
}

void	comment_len(t_asm *e)
{
	int		start;
	char	*nbr;

	start = 0;
	nbr = NULL;
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.comment) + 1) > 30)
		e->verbos.len_arrow = 30;
	add_cont(e, &V_LINE, WHITE "Champion's description too long {" GREY);
	if (!(nbr = ft_itoa(ft_strlen(e->champ.valid.comment))))
		error(e, MALLOC);
	ft_memdel((void **)&e->champ.valid.comment);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
	add_cont(e, &V_LINE, WHITE "}, max description len: {" GREY);
	if (!(nbr = ft_itoa(COMMENT_LENGTH)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
	add_cont(e, &V_LINE, WHITE "}");
	(void)e;
}

/*
**	void	syntax(t_asm *e);
*/

/*
**	void	invalid_char(t_asm *e);
*/
