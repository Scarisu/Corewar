/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:25:27 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/28 21:04:33 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		verbos(t_asm *e, int err)
{
	++e->verbos.nb_error;
	e->verbos.frag->coo[0] = e->verbos.nb_line;
	e->verbos.frag->coo[1] = I;
	e->verbos.frag->type = ERROR;
	if (!(e->verbos.frag->print = ft_strnew(1)))
		error(e, MALLOC);
	print_pos(e, err);
	add_cont(e, &V_LINE, " error: ");
	e->verbos.tab[err](e);
	ft_putstr_fd(RESET "\n", 2);
	if (err != MISSING_NAME &&
		err != MISSING_COMMENT)
	{
		adapt_line(e, e->champ.line);
		arrow(e);
	}
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
	int	start;
	int end;

	start = 0;
	end = I + 30;
	if (I > 30)
	{
		start = I - 30;
		add_cont(e, &V_LINE, "  ...");
		I = 35;
	}
	while (line[start] && start <= end && line[start] != '\n')
		add_cont(e, &V_LINE, &line[start++]);
	if (line[start] && line[start] != '\n')
		add_cont(e, &V_LINE, "...");
	add_cont(e, &V_LINE, "\n");
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

void	add_cont(t_asm *e, char **line, char const *add)
{
	size_t	l[2];
	char	*final;

	l[0] = (*line) ? ft_strlen(*line) : 0;
	l[1] = (add) ? ft_strlen(add) : 0;
	if (!(final = (char *)malloc(sizeof(char) * (l[0] + l[1] + 1))))
		error(e, MALLOC);
	final[l[0] + l[1]] = '\0';
	ft_memcpy(l, ((size_t[2]){-1, 0}), sizeof(size_t[2]));
	while ((*line)[++l[0]])
		final[l[0]] = (*line)[l[0]];
	ft_memdel((void **)line);
	while (add[l[1]])
		final[l[0]++] = add[l[1]++];
	*line = final;
}
