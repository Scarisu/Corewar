/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:18:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/09 01:19:55 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

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
			return (ret);
		if (BUFF == '\t')
			BUFF = ' ';
		ft_strjoin_clean_char(line, BUFF);
		++size;
	}
	return (size);
}

void	check_line(t_asm *e)
{
	int i;

	while (e->verbos.nb_error <= 10 &&
		(e->verbos.line_left = get_line(e, &e->champ.line)))
	{
		i = 0;
		while (i < 2 && (e->tab[i](e, e->champ.line)))
			++i;
		ft_memdel((void **)&e->champ.valid.prev);
		if (!(e->champ.valid.prev = ft_strdup(e->champ.line)))
			error(e, MALLOC);
		ft_strjoin_clean(&e->champ.all, &e->champ.line);
		ft_memdel((void **)&e->champ.line);
		++e->verbos.nb_line;
	}
	ft_memdel((void **)&e->champ.valid.prev);
	ft_memdel((void **)&e->champ.line);
	if (!(e->verbos.line_left) && !e->champ.valid.name_done)
		verbos(e, MISSING_NAME);
	if (!(e->verbos.line_left) && !e->champ.valid.comment_done)
		verbos(e, MISSING_COMMENT);
}

int		skip_tab(t_asm *e, char *line)
{
	while (line[I] == ' ')
		++I;
	if (line[I] == COMMENT_CHAR)
	{
		I += (I != 0) ? -1 : 0;
		return (0);
	}
	return (1);
}
