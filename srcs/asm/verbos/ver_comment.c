/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:52:00 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/20 19:06:54 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	comment_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(COMMENT_CMD_STRING) - 1) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Champion's description already set", 2);
	if ((e->champ.valid.comment))
	{
		ft_putstr_fd(": \"" GREY, 2);
		ft_putstr_fd(e->champ.valid.comment, 2);
		ft_putstr_fd(WHITE "\"", 2);
	}
}

void	comment_len(t_asm *e)
{
	int start;

	start = 0;
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.comment) + 1) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Champion's description too long {" GREY, 2);
	ft_putnbr_fd(ft_strlen(e->champ.valid.comment), 2);
	ft_memdel((void **)&e->champ.valid.comment);
	ft_putstr_fd(WHITE "}, max description len: {", 2);
	ft_putstr_fd(GREY, 2);
	ft_putnbr_fd(COMMENT_LENGTH, 2);
	ft_putstr_fd(WHITE "}", 2);
	(void)e;
}

/*
**	void	syntax(t_asm *e);
*/

/*
**	void	invalid_char(t_asm *e);
*/
