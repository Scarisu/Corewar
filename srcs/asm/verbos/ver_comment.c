/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:52:00 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/08 23:33:57 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	comment_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(COMMENT_CMD_STRING) - 1) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Champion's description already set: \"" GREY, 2);
	ft_putstr_fd(e->champ.valid.comment, 2);
	ft_putstr_fd(WHITE "\"", 2);
}

/*
**	void	syntax(t_asm *e);
*/

/*
**	void	invalid_char(t_asm *e);
*/
