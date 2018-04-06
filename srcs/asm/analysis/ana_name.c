/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:35:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/05 21:51:23 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		cmd_name(t_asm *e, char *line)
{
	if (!(ft_strstr(line, NAME_CMD_STRING) == &(line)[I]))
		return (1);
	if ((e->champ.valid.name_done))
		return (verbos(e, NAME_EXIST));
	e->champ.valid.name_done = 1;
	I += ft_strlen(NAME_CMD_STRING);
	if (!skip_tab(e, line) || (line[I] != '\"' && line[I] != '\''))
		return (verbos(e, SYNTAX));
	if (!save_name(e, line) || !skip_tab(e, line))
		return (0);
	if (line[I] && line[I] != '\n')
		return (verbos(e, INVALID_CHAR));
	return (0);
}

int		save_name(t_asm *e, char *line)
{
	int		content_len;

	content_len = I + 1;
	while (line[content_len]
		&& line[content_len] != line[I]
		&& line[content_len] != COMMENT_CHAR)
		++content_len;
	if (!line[content_len] || line[content_len] == COMMENT_CHAR)
		return (verbos(e, SYNTAX));
	content_len -= I + 1;
	if (!(e->champ.valid.name = ft_strsub(line, I + 1, content_len)))
		error(e, MALLOC);
	if (content_len > PROG_NAME_LENGTH)
		return (verbos(e, NAME_LEN));
	I += content_len + 2;
	return (1);
}
