/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_diverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:11:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/13 23:05:24 by pbernier         ###   ########.fr       */
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
	int		nb_inv;
	int		nb_uni;
	char	inv[6];

	i = I;
	nb_inv = 0;
	nb_uni = 0;
	ft_bzero(inv, 6);
	while (e->champ.line[i] && (i - (I + 1)) < 30
		&& e->champ.line[i] != '\n' && e->champ.line[i] != ' '
		&& e->champ.line[i] != COMMENT_CHAR)
	{
		if (!((int)e->champ.line[i] <= 127 && e->champ.line[i] >= 0))
			++nb_uni;
		else if (!ft_strchr(inv, e->champ.line[i]) && ++nb_inv < 6)
			inv[ft_strlen(inv)] = e->champ.line[i];
		++i;
	}
	e->verbos.len_arrow = i - (I + 1) - (nb_uni / 2);
	print_invalid_char(nb_inv, nb_uni, inv);
}

void	print_invalid_char(int nb_inv, int nb_uni, char inv[31])
{
	int		print;

	print = -1;
	ft_putstr_fd(WHITE "Invalid character", 2);
	nb_inv > 1 ? ft_putchar_fd('s', 2) : 0;
	ft_putstr_fd(": {" GREY, 2);
	while (inv[++print])
	{
		(print) ? ft_putstr_fd(WHITE "," GREY, 2) : 0;
		ft_putchar_fd(inv[print], 2);
	}
	if ((print) && (nb_uni))
		ft_putstr_fd(WHITE ", ", 2);
	else if (ft_strlen(inv) < (size_t)nb_inv)
		ft_putstr_fd(WHITE " ", 2);
	if ((nb_uni) || ft_strlen(inv) < (size_t)nb_inv)
		ft_putstr_fd(WHITE "...", 2);
	ft_putstr_fd(WHITE "}", 2);
}
