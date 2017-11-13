/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:36:15 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/13 19:19:11 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	label_invalid_char(t_asm *e)
{
	// int		i;
	// int		print;
	// char	invalid[31];
	//
	// i = I;
	// print = -1;
	// ft_bzero(invalid, 31);
	// while (e->champ.line[i] && (i - (I + 1)) < 30
	// 	&& e->champ.line[i] != '\n'
	// 	&& e->champ.line[i] != ' '
	// 	&& e->champ.line[i] != LABEL_CHAR
	// 	&& e->champ.line[i] != COMMENT_CHAR)
	// {
	// 	if (!ft_strchr(LABEL_CHARS, e->champ.line[i]) &&
	// 		!ft_strchr(invalid, e->champ.line[i]))
	// 		invalid[ft_strlen(invalid)] = e->champ.line[i];
	// 	++i;
	// }
	// e->verbos.len_arrow = i - (I + 1);
	// ft_putstr_fd(WHITE "Invalid character", 2);
	// ft_strlen(invalid) > 1 ? ft_putchar_fd('s', 2) : 0;
	// ft_putstr_fd(" used for label: {" GREY, 2);
	// while (invalid[++print])
	// {
	// 	(print) ? ft_putstr_fd(WHITE "," GREY, 2) : 0;
	// 	ft_putchar_fd(invalid[print], 2);
	// }
	// ft_putstr_fd(WHITE "}", 2);
	(void)e;
}
