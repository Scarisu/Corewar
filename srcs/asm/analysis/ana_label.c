/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 03:01:03 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/23 09:59:32 by pbernier         ###   ########.fr       */
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

void	label_mutli(t_asm *e)
{
	e->champ.valid.label = e->champ.valid.label_start;
	while (e->champ.valid.label)
	{
		e->verbos.pars = e->champ.valid.label->next;
		e->verbos.prev_pars = e->champ.valid.label;
		while (e->verbos.pars && e->verbos.pars->name)
		{
			if (!ft_strcmp(e->champ.valid.label->name, e->verbos.pars->name))
			{
				if (!(e->champ.line = ft_strdup(e->verbos.pars->line)))
				 	error(e, MALLOC);
				ft_memdel((void **)&e->verbos.pars->line);
				e->verbos.nb_line = e->verbos.pars->coo[0];
				I = e->verbos.pars->coo[1];
				verbos(e, LABEL_MULTI_INIT);
				ft_memdel((void **)&e->champ.line);
				e->verbos.prev_pars->next = e->verbos.pars->next;
				ft_memdel((void **)&e->verbos.pars);
				e->verbos.pars = e->verbos.prev_pars;
			}
			else
				e->verbos.prev_pars = e->verbos.pars;
			e->verbos.pars = e->verbos.pars->next;
		}
		e->champ.valid.label = e->champ.valid.label->next;
	}
}

// void	label_exist(t_asm *e)
// {
// 	e->champ.valid.check = e->champ.valid.check_start;
// 	while (e->champ.valid.check && e->champ.valid.check->name)
// 	{
// 		e->champ.valid.label = e->champ.valid.label_start;
// 		while (e->champ.valid.label && e->champ.valid.label->name
// 		&& ft_strcmp(e->champ.valid.label->name, e->champ.valid.check->name))
// 			e->champ.valid.label = e->champ.valid.label->next;
// 		if (e->champ.valid.label->name)
// 			ft_memcpy(e->champ.valid.label->coo, (int[2]){0,0} , sizeof(int[2]));
// 		else
// 			printf("balo\n");
// 			//verbos
//
// 	}
// 	(void)e;
// }
