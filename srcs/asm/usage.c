/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:39:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 00:06:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	usage(t_asm *e, int argc, char *argv)
{
	int	len;

	if (argc != 2)
		error(e, NB_ARG);
	len = ft_strlen(argv);
	e->champ.file_name = argv;
	if (e->champ.file_name[len - 2] != '.' &&
		e->champ.file_name[len - 1] != 's')
		error(e, EXTENTION);
	if ((e->champ.fd = open(e->champ.file_name, O_RDONLY)) < 2)
		error(e, OPEN_CHAMP);
	e->champ.file_name[len - 1] = '\0';
	e->champ.file_name[len - 2] = '\0';
}
