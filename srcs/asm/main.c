/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:27:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/01 01:36:49 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		main(int argc, char **argv)
{
	t_asm	e;

	set_data(&e);
	set_ptrft(&e);
	set_ptrver(&e);
	usage(&e, argc, argv[1]);
	check_line(&e);
	if (!print_verbos(&e.verbos))
		create_cor(&e);
	clean(&e);
	return (0);
}

int		print_verbos(t_verbos *v)
{
	int		left;
	t_frag	*print;

	if (!(left = v->nb_error + v->nb_warning))
		return (0);
	while (left)
	{
		v->frag = v->frag_start;
		print = NULL;
		while (v->frag && v->frag->next)
		{
			if (v->frag->coo[0] != -1 &&
			(!print || v->frag->coo[0] < print->coo[0]))
				print = v->frag;
			v->frag = v->frag->next;
		}
		ft_putstr_fd(print->print, 2);
		--left;
		print->coo[0] = -1;
		print->coo[1] = -1;
	}
	return (nb_error(v));
}

int		nb_error(t_verbos *v)
{
	if ((v->line_left))
		ft_putstr_fd("Minimun ", 2);
	ft_putnbr_fd(v->nb_error + v->nb_warning, 2);
	(!v->nb_error) ? ft_putstr_fd(" warning", 2) : ft_putstr_fd(" error", 2);
	(v->nb_error + v->nb_warning > 1) ? ft_putchar_fd('s', 2) : 0;
	ft_putstr_fd(" generated.\n", 2);
	return (v->nb_error);
}

int		create_cor(t_asm *e)
{
	int	fd;

	add_cont(e, &e->champ.file_path, e->champ.file_name);
	add_cont(e, &e->champ.file_path, ".cor");
	if ((fd = open(e->champ.file_path,
		O_CREAT | O_RDWR | O_TRUNC, 0755)) < 2)
		error(e, CREATE);
	ft_putstr_fd(e->head, fd);
	return (1);
}
