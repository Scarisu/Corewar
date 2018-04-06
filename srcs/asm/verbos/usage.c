/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:39:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/01 01:01:36 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	usage(t_asm *e, int argc, char **av)
{
	int	len;

	if (argc != 2 && argc != 3)
		error(e, NB_ARG);
	if (argc == 3)
		flag(e, av[1]);
	len = ft_strlen(av[argc - 1]);
	if (av[argc - 1][len - 2] != '.' && av[argc - 1][len - 1] != 's')
		error(e, EXTENTION);
	if ((e->champ.fd = open(av[argc - 1], O_RDONLY)) < 2)
		error(e, OPEN_CHAMP);
	len -= 3;
	while (len > 0 && av[argc - 1][len] != '/')
		--len;
	len += (av[argc - 1][len] == '/') ? 1 : 0;
	if (!(e->champ.file_path = ft_strsub(av[argc - 1], 0, len)))
		error(e, MALLOC);
	if (!(e->champ.file_name = ft_strsub(av[argc - 1], len,
		ft_strlen(av[argc - 1]) - len - 2)))
		error(e, MALLOC);
}

void	flag(t_asm *e, char *av)
{
	int	i;

	i = 0;
	if (av[i] != '-' || ft_strlen(av) == 1)
		error(e, USAGE);
	while (av[++i])
		av[i] != 's' ? error(e, USAGE) : (e->flag = 1);
}
