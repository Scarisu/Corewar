/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:18:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/29 20:32:35 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		get_line(t_asm *e, char **line)
{
	int		ret;
	int		size;

	size = 0;
	BUFF = 'A';
	if (!(*line = malloc(sizeof(char) * (size + 1))))
		error(e, MALLOC);
	(*line)[size] = '\0';
	while (BUFF != '\n')
	{
		if ((ret = read(e->champ.fd, e->champ.buff, 1)) == -1)
			error(e, READ_CHAMP);
		if (!ret || BUFF == 0)
			return (0);
		if (BUFF == '\t' || BUFF == '\r' || BUFF == '\v' || BUFF == '\f')
			BUFF = ' ';
		ft_strjoin_clean_char(line, BUFF);
		++size;
	}
	return (size);
}

void	check_line(t_asm *e, t_verbos *v, t_champ *c)
{
	int i;

	while ((!v->nb_error || ((v->nb_error)
		&& (v->nb_line - v->frag_start->coo[0]) < MAX_LINE))
		&& (v->line_left = get_line(e, &c->line)))
	{
		i = 0;
		I = 0;
		while (i < 6 && (e->tab[i](e, c->line)))
			++i;
		ft_memdel((void **)&c->line);
		++v->nb_line;
	}
	ft_memdel((void **)&c->line);
	label_mutli(e, v, &c->valid);
	if (!v->line_left)
	{
		set_file(e, e->enco);
		used_label(e, &c->valid);
		if ((e->bin.len_file > CHAMP_MAX_SIZE || e->bin.len_file <= 0) &&
			!v->nb_error)
			verbos(e, CHAMP_TOO_LONG);
		!c->valid.name_done ? verbos(e, MISSING_NAME) : 0;
		!c->valid.comment_done ? verbos(e, MISSING_COMMENT) : 0;
	}
}
