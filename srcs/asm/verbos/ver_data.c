/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:11:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/09 01:23:14 by pbernier         ###   ########.fr       */
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
