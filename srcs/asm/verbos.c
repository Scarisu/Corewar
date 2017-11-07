/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:25:27 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 22:35:24 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		verbos(t_asm *e, t_verbos *v, int err)
{
	printf("verbos : [%d]\n", err);
	++v->nb_error;
	print_pos(e);
	verbos_error(e, err);
	adapt_line(e, e->champ.line);
	arrow(e, &e->verbos.arrow);
	return (0);
}

void	print_pos(t_asm *e)
{
	ft_putstr_fd(GRAS WHITE, 2);
	ft_putstr_fd(e->champ.file_path, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(e->verbos.nb_line, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(I + 1, 2);
	ft_putstr_fd(": ", 2);
}

void	verbos_error(t_asm *e, int err)
{
	ft_putstr_fd(RED_MINUS "error: ", 2);
	if (err == NAME_EXIST)
	{
		ft_putstr_fd(WHITE "Champion's name already set: \"" GREY, 2);
		ft_putstr_fd(e->champ.valid.name, 2);
		ft_putstr_fd(WHITE "\"", 2);
	}
	if (err == SYN_NAME)
		ft_putstr_fd(WHITE "Syntax error", 2);
	if (err == INVALID_NAME)
	{
		ft_putstr_fd(WHITE "Champion's name can't be null ", 2);
		ft_putstr_fd("or contain { /\\:*?\"<>| }", 2);
	}
	if (err == NAME_DIFF_FILE)
	{
		ft_putstr_fd(WHITE "Champion's is name different from ", 2);
		ft_putstr_fd("the orignal file: {\"" GREY, 2);
		ft_putstr_fd(e->champ.file_name, 2);
		ft_putstr_fd(WHITE "\", \"" GREY, 2);
		ft_putstr_fd(e->champ.valid.name, 2);
		ft_putstr_fd(WHITE "\"}", 2);
	}
	if (err == INVALID_CHAR)
	{
		ft_putstr_fd(WHITE "Invalid char: \"" GREY, 2);
		ft_putchar_fd(e->champ.line[I], 2);
		ft_putstr_fd(WHITE "\"", 2);
	}
	ft_putstr_fd(RESET "\n", 2);
}

void	adapt_line(t_asm *e, char *line)
{
	int	start;
	int end;

	ft_putstr_fd(line, 2);
	(void)e;
	(void)start;
	(void)end;
	(void)line;
}

void	arrow(t_asm *e, char **arrow)
{
	int	space;

	space = 0;
	while (space++ != I)
		ft_putchar_fd(' ', 2);
	ft_putstr_fd(GREEN_MINUS, 2);
	ft_putstr_fd(*arrow, 2);
	ft_putstr_fd(RESET, 2);
}
