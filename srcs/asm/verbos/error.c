/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:41:14 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/01 01:19:02 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	error(t_asm *e, int err)
{
	err == NB_ARG || err == USAGE || err == EXTENTION ?
		ft_putstr_fd("usage: asm [-s] {file}.s\n", 2) : ft_putstr_fd("asm:", 2);
	err == OPEN_CHAMP ? ft_putstr_fd(" Can't open champ\n", 2) : 0;
	err == READ_CHAMP ? ft_putstr_fd(" Can't read champ\n", 2) : 0;
	err == MALLOC ? ft_putstr_fd(" Malloc error\n", 2) : 0;
	err == CREATE ? ft_putstr_fd(" Can't create file cor\n", 2) : 0;
	clean(e);
	exit(err);
}
