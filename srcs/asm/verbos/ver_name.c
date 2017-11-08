/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:56:01 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/08 19:58:41 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	name_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(NAME_CMD_STRING) - 1) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Champion's name already set: \"" GREY, 2);
	ft_putstr_fd(e->champ.valid.name, 2);
	ft_putstr_fd(WHITE "\"", 2);
}

void	syntax_name(t_asm *e)
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

void	invalid_name(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.name) + 1) > 30)
		e->verbos.len_arrow = 30;
	ft_memdel((void **)&e->champ.valid.name);
	ft_putstr_fd(WHITE "Champion's name can't be null ", 2);
	ft_putstr_fd("or contain { /\\:*?\"<>| }", 2);
}

void	name_diff_file(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.name) + 1) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Champion's name is different from ", 2);
	ft_putstr_fd("the orignal file: {\"" GREY, 2);
	ft_putstr_fd(e->champ.file_name, 2);
	ft_putstr_fd(WHITE "\", \"" GREY, 2);
	ft_putstr_fd(e->champ.valid.name, 2);
	ft_memdel((void **)&e->champ.valid.name);
	ft_putstr_fd(WHITE "\"}", 2);
}

void	invalid_char(t_asm *e)
{
	int		i;
	int		print;
	char	invalid[31];

	i = I;
	print = -1;
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
	 	if (print)
			ft_putstr_fd(WHITE "," GREY, 2);
	 	ft_putchar_fd(invalid[print], 2);
	}
	ft_putstr_fd(WHITE "}", 2);
}
