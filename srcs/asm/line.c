/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:18:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/02 22:07:52 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		line(t_asm *e, char **line)
{
	int ret;
	int size;

	if ((ret = read(e->fd, e->champ.buff, 1)) == -1)
		error(e, READ);
	if (!ret || BUFF == 0)
		return (ret);
	size = 1;
	
	return (0);
}
