/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_diverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 01:32:42 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/14 19:33:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		skip_tab(t_asm *e, char *line)
{
	while (line[I] && line[I] == ' ')
		++I;
	if (line[I] &&line[I] == COMMENT_CHAR)
	{
		I += (I != 0) ? -1 : 0;
		return (0);
	}
	if (!line[I] || line[I] == '\n')
		return (0);
	return (1);
}

void	missing_data(t_asm *e)
{
	if (!(e->verbos.line_left) && !e->champ.valid.name_done)
		verbos(e, MISSING_NAME);
	if (!(e->verbos.line_left) && !e->champ.valid.comment_done)
		verbos(e, MISSING_COMMENT);
}

int		cmd_check(t_asm *e, char *line)
{
	int	cmd_len;

	if (line[I] != '.')
		return (1);
	cmd_len = I + 1;
	while (line[cmd_len]
		&& line[cmd_len] != ' '
		&& line[cmd_len] != '\n'
		&& line[cmd_len] != COMMENT_CHAR)
		++cmd_len;
	if (!(e->verbos.cmd_invalid = ft_strsub(line, I + 1, cmd_len - (I + 1))))
		error(e, MALLOC);
	return (verbos(e, INVALID_COMMANDE));
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
