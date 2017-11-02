/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:39:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/02 21:15:19 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	usage(t_asm *e, int argc, char *argv)
{
	int	len;

	if (argc != 2)
		error(e, NB_ARG);
	len = ft_strlen(argv);
	e->name = argv;
	if (e->name[len - 2] != '.' &&
		e->name[len - 1] != 's')
		error(e, EXTENTION);
	if ((e->fd = open(e->name, O_RDONLY)) < 2)
		error(e, FD);
	e->name[len - 1] = '\0';
	e->name[len - 2] = '\0';
}
