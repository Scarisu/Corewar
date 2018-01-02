/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:25:27 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/05 21:52:54 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		verbos(t_asm *e, int err)
{
	if (err == LABEL_USED && e->flag)
		return (0);
	(err == LABEL_USED) ? (++e->verbos.nb_warning) : (++e->verbos.nb_error);
	if (err != MISSING_NAME && err != MISSING_COMMENT)
		ft_memcpy(e->verbos.frag->coo,
			(int[2]){e->verbos.nb_line, I + 1}, sizeof(int[2]));
	if (!(e->verbos.frag->print = ft_strnew(1)))
		error(e, MALLOC);
	print_pos(e, err);
	err == LABEL_USED ? add_cont(e, &V_LINE, PINK " warning: ") :
		add_cont(e, &V_LINE, RED_MINUS " error: ");
	e->verbos.tab[err](e);
	add_cont(e, &V_LINE, RESET "\n");
	if (err != MISSING_NAME && err != MISSING_COMMENT)
		adapt_line(e, e->champ.line);
	e->verbos.frag->next = set_frag(e, (int[2]){0, 0});
	e->verbos.frag = e->verbos.frag->next;
	return (0);
}

void	print_pos(t_asm *e, int err)
{
	char	*nbr;

	nbr = NULL;
	add_cont(e, &V_LINE, GRAS);
	add_cont(e, &V_LINE, WHITE);
	add_cont(e, &V_LINE, e->champ.file_path);
	add_cont(e, &V_LINE, e->champ.file_name);
	add_cont(e, &V_LINE, ":");
	if (err == MISSING_NAME || err == MISSING_COMMENT)
		return ;
	if (!(nbr = ft_itoa(e->verbos.nb_line)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
	add_cont(e, &V_LINE, ":");
	if (!(nbr = ft_itoa(I + 1)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
	add_cont(e, &V_LINE, ":");
}

void	adapt_line(t_asm *e, char *line)
{
	int		start;
	int		end;
	char	tmp[2];

	start = 0;
	end = I + 30;
	if (I > 30)
	{
		start = I - 30;
		add_cont(e, &V_LINE, "  ...");
		I = 35;
	}
	while (line[start] && start <= end && line[start] != '\n')
	{
		ft_memcpy(tmp, (char[2]){line[start++], '\0'}, sizeof(char[2]));
		add_cont(e, &V_LINE, tmp);
	}
	if (line[start] && line[start] != '\n')
		add_cont(e, &V_LINE, "...");
	add_cont(e, &V_LINE, "\n");
	arrow(e);
}

void	arrow(t_asm *e)
{
	int	space;

	space = 0;
	while (space++ != I)
		add_cont(e, &V_LINE, " ");
	add_cont(e, &V_LINE, GREEN_MINUS "^");
	while (e->verbos.len_arrow-- > 0)
		add_cont(e, &V_LINE, "~");
	add_cont(e, &V_LINE, RESET "\n");
}

int		print_verbos(t_verbos *v)
{
	int		left;
	t_frag	*print;

	if ((left = v->nb_error + v->nb_warning + 1) == 1)
		return (0);
	while (--left)
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
		ft_memcpy(print->coo, (int[2]){-1, -1}, sizeof(int[2]));
	}
	((v->line_left)) ? ft_putstr_fd("Minimun ", 2) : 0;
	ft_putnbr_fd(v->nb_error + v->nb_warning, 2);
	(!v->nb_error) ? ft_putstr_fd(" warning", 2) : ft_putstr_fd(" error", 2);
	(v->nb_error + v->nb_warning > 1) ? ft_putchar_fd('s', 2) : 0;
	ft_putstr_fd(" generated.\n", 2);
	return (v->nb_error);
}
