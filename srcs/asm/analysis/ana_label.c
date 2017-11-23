/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 03:01:03 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/23 03:05:33 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		ins_label(t_asm *e, char *line)
{
	int	content_len;

	content_len = I;
	while (line[content_len]
		&& line[content_len] != LABEL_CHAR
		&& line[content_len] != ' ')
			++content_len;
	if (line[content_len] != LABEL_CHAR)
		return (1);
	content_len -= I;
	if (!(e->champ.valid.label->name = ft_strsub(line, I, content_len)))
		error(e, MALLOC);
	if (!valid_label(e->champ.valid.label->name))
		return (verbos(e, INVALID_LABEL));
	e->champ.valid.label->next = set_label(e, (int[2]){e->verbos.nb_line, I});
	e->champ.valid.label = e->champ.valid.label->next;
	I += content_len + 1;
	return (1);
}

int		valid_label(char *name)
{
	int		i;

	i = -1;
	if (!ft_strlen(name))
		return (0);
	while (name[++i])
		if (!ft_strchr(LABEL_CHARS, name[i]))
			return (0);
	return (1);
}
