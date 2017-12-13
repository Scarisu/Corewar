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

// void	test(t_asm *e)
// {
// 	int i = -1;
// 	printf("[");
// 	while (e->enco->hexa[++i])
// 		printf("%d", e->enco->hexa[i]);
// 	printf("].");
// 	if (e->enco->arg_label)
// 		printf("[%s]", e->enco->arg_label->name);
// 	printf("\n");
// }

void	set_file(t_asm *e)
{
	e->enco = e->enco_start;
	while (e->enco && (e->enco->hexa || e->enco->arg_label))
	{
		if (e->enco->hexa[0])
			add_cont(e, &e->file, e->enco->hexa);
		if (e->enco->arg_label)
			exist_label(e, e->enco->arg_label, &e->champ.valid);
		//test(e);
		e->enco = e->enco->next;
	}
}

int		exist_label(t_asm *e, t_label *exi, t_valid *val)
{
	val->label = val->label_start;
	while (val->label && val->label->next)
	{
		if (!ft_strcmp(val->label->name, exi->name))
		{
			add_cont(e, &e->enco->hexa,
				(char[2]){val->label->octets - exi->octets, '\0'});
			val->label->used = 1;
			return (1);
		}
		val->label = val->label->next;
	}
	if (!(e->champ.line = ft_strdup(exi->line)))
	 	error(e, MALLOC);
	e->verbos.nb_line = exi->coo[0];
	I = exi->coo[1];
	verbos(e, LABEL_EXIST);
	ft_memdel((void **)&e->champ.line);
	return (0);
}

void	used_label(t_asm *e, t_valid *val)
{
	val->label = val->label_start;
	while (val->label && val->label->next)
	{
		if (!val->label->used)
		{
			if (!(e->champ.line = ft_strdup(val->label->line)))
			 	error(e, MALLOC);
			e->verbos.nb_line = val->label->coo[0];
			I = val->label->coo[1];
			verbos(e, LABEL_USED);
			ft_memdel((void **)&e->champ.line);
		}
		val->label = val->label->next;
	}
	(void)e;
	(void)val;
}


































//
