/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:41:14 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/02 22:03:53 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	error(t_asm *e, int err)
{
	err == NB_ARG ? ft_putstr_fd("pd nb arg\n", 2) : 0;
	err == EXTENTION ? ft_putstr_fd("pd d extention\n", 2) : 0;
	err == OPEN ? ft_putstr_fd("Can't open\n", 2) : 0;
	(void)e;
	exit(err);
}
