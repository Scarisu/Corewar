/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_diverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:11:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/09 18:21:28 by pbernier         ###   ########.fr       */
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

void	syntax(t_asm *e)
{
	int	i;

	i = I + 1;
	while (e->champ.line[i] && (i - (I + 1)) < 30
		&& e->champ.line[i] != '\n' && e->champ.line[i] != ' '
		&& e->champ.line[i] != COMMENT_CHAR)
		++i;
	e->verbos.len_arrow = i - (I + 1);
	ft_putstr_fd(WHITE "Syntax error", 2);
}

void	invalid_char(t_asm *e)
{
	int		i;
	int		print;
	char	invalid[31];

	i = I;
	print = -1;
	ft_bzero(invalid, 31);
	while (e->champ.line[i] && (i - (I + 1)) < 30
		&& e->champ.line[i] != '\n' && e->champ.line[i] != ' '
		&& e->champ.line[i] != COMMENT_CHAR)
	{
		if (!ft_strchr(invalid, e->champ.line[i]))
			invalid[ft_strlen(invalid)] = e->champ.line[i];
		++i;
	}
	e->verbos.len_arrow = i - (I + 1);
	ft_putstr_fd(WHITE "Invalid character", 2);
	ft_strlen(invalid) > 1 ? ft_putchar_fd('s', 2) : 0;
	ft_putstr_fd(": {" GREY, 2);
	while (invalid[++print])
	{
		(print) ? ft_putstr_fd(WHITE "," GREY, 2) : 0;
		ft_putchar_fd(invalid[print], 2);
	}
	ft_putstr_fd(WHITE "}", 2);
}
