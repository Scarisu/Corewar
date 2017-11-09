/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_diverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:11:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/09 04:35:34 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	missing_name(t_asm *e)
{
	ft_putstr_fd(WHITE "Missing champion's name\n", 2);
	ft_putstr_fd(RESET "usage: " GREY NAME_CMD_STRING	" \"name\"", 2);
	ft_putstr_fd(RESET "\n", 2);
	(void)e;
}

void	missing_comment(t_asm *e)
{
	ft_putstr_fd(WHITE "Missing champion's description\n", 2);
	ft_putstr_fd(RESET "usage: " GREY COMMENT_CMD_STRING " \"description\"", 2);
	ft_putstr_fd(RESET "\n", 2);
	(void)e;
}

void	invalid_command(t_asm *e)
{
	int start;

	start = 0;
	if ((e->verbos.len_arrow = ft_strlen(e->verbos.cmd_invalid)) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Command \"" GREY, 2);
	while (e->verbos.cmd_invalid[start] && start < 30)
		ft_putchar_fd(e->verbos.cmd_invalid[start++], 2);
	if (start == 30 && ft_strlen(e->verbos.cmd_invalid) > 30)
		ft_putstr_fd(WHITE " ...", 2);
	ft_memdel((void **)&e->verbos.cmd_invalid);
	ft_putstr_fd(WHITE "\" doesn't exist", 2);
}
