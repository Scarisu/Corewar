/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:35:29 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/13 23:53:08 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		ins_label(t_asm *e, char *line)
{
	int 	content_len;

	I = 0;
	//MAUVAISE VERIF
	if (!skip_tab(e, line) || !ft_strchr(line, LABEL_CHAR))
		return (1);
	content_len = I;
	while (line[content_len]
		&& line[content_len] != LABEL_CHAR)
		if (line[content_len++] == ' ')
			return (verbos(e, SYNTAX));
	content_len -= I;
	if (!(e->champ.valid.label->name = ft_strsub(line, I, content_len)))
		error(e, MALLOC);
	if (!valid_label(e->champ.valid.label->name))
		return (verbos(e, INVALID_LABEL));
	e->champ.valid.label->next = set_label(e, (int[2]){e->verbos.nb_line, I});
	e->champ.valid.label = e->champ.valid.label->next;
	return (0);
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
