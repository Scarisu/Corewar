/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:25:27 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/08 22:25:47 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		verbos(t_asm *e, int err)
{
	++e->verbos.nb_error;
	print_pos(e);
	ft_putstr_fd(RED_MINUS "error: ", 2);
	e->verbos.tab[err](e);
	ft_putstr_fd(RESET "\n", 2);
	adapt_line(e, e->champ.line);
	arrow(e);
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

void	adapt_line(t_asm *e, char *line)
{
	int	start;
	int end;

	start = 0;
	end = I + 30;
	if (I > 30)
	{
		start = I - 30;
		ft_putstr_fd("  ...", 2);
		I = 35;
	}
	while (line[start] && start <= end && line[start] != '\n')
		ft_putchar_fd(line[start++], 2);
	if (line[start] && line[start] != '\n')
		ft_putstr_fd("...", 2);
	ft_putchar_fd('\n', 2);
}

void	arrow(t_asm *e)
{
	int	space;

	space = 0;
	while (space++ != I)
		ft_putchar_fd(' ', 2);
	ft_putstr_fd(GREEN_MINUS "^", 2);
	while (e->verbos.len_arrow-- > 0)
		ft_putchar_fd('~', 2);
	ft_putstr_fd(RESET "\n", 2);
}
