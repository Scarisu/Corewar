/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:41:14 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 01:46:50 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	error(t_asm *e, int err)
{
	err == NB_ARG ? ft_putstr_fd("pd nb arg\n", 2) : 0;
	err == EXTENTION ? ft_putstr_fd("pd d extention\n", 2) : 0;
	err == NB_ARG || err == EXTENTION ? exit(err) : 0;
	err == OPEN_CHAMP ? ft_putstr_fd("Can't open champ\n", 2) : 0;
	err == READ_CHAMP ? ft_putstr_fd("Can't read champ\n", 2) : 0;
	err == MALLOC ? ft_putstr_fd("MALLOC error\n", 2) : 0;
	clean(e);
	exit(err);
}
