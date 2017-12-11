/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 03:01:03 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/11 21:37:26 by pbernier         ###   ########.fr       */
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
	e->champ.valid.label->coo[0] = e->verbos.nb_line;
	e->champ.valid.label->coo[1] = I;
	e->champ.valid.label->octets = e->size;
	if (!(e->champ.valid.label->line = ft_strdup(line)))
		error(e, MALLOC);
	e->champ.valid.label->next = set_label(e, (int[2]){0, 0});
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

void	label_mutli(t_asm *e, t_verbos *ver, t_valid *val)
{
	val->label = val->label_start;
	while (val->label)
	{
		ver->pars = val->label->next;
		ver->prev_pars = val->label;
		while (ver->pars && ver->pars->name)
		{
			if (!ft_strcmp(val->label->name, ver->pars->name))
			{
				if (!(e->champ.line = ft_strdup(ver->pars->line)))
					error(e, MALLOC);
				ft_memdel((void **)&ver->pars->line);
				ver->nb_line = ver->pars->coo[0];
				I = ver->pars->coo[1];
				verbos(e, LABEL_MULTI_INIT);
				ft_memdel((void **)&e->champ.line);
				ver->prev_pars->next = ver->pars->next;
				ft_memdel((void **)&ver->pars);
				ver->pars = ver->prev_pars;
			}
			else
				ver->prev_pars = ver->pars;
			ver->pars = ver->pars->next;
		}
		val->label = val->label->next;
	}
}
