/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:51:26 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/09 20:42:29 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cmd_comment(t_asm *e, char *line)
{
	I = 0;
	if (!skip_tab(e, line) ||
		!(ft_strstr(line, COMMENT_CMD_STRING) == &(line)[I]))
		return (1);
	if ((e->champ.valid.comment_done))
		return (verbos(e, COMMENT_EXIST));
	e->champ.valid.comment_done = 1;
	I += ft_strlen(COMMENT_CMD_STRING);
	if (!skip_tab(e, line) || (line[I] != '\"' && line[I] != '\''))
		return (verbos(e, SYNTAX));
	if (!save_comment(e, line) || !skip_tab(e, line))
		return (0);
	if (line[I] && line[I] != '\n')
		return (verbos(e, INVALID_CHAR));
	return (0);
}

int		save_comment(t_asm *e, char *line)
{
	int		content_len;

	content_len = I + 1;
	while (line[content_len] && line[content_len] != line[I]
		&& line[content_len] != COMMENT_CHAR)
		++content_len;
	if (!line[content_len] || line[content_len] == COMMENT_CHAR)
		return (verbos(e, SYNTAX));
	content_len -= I + 1;
	if (!(e->champ.valid.comment = ft_strsub(line, I + 1, content_len)))
		error(e, MALLOC);
	if (content_len > COMMENT_LENGTH)
		return (verbos(e, COMMENT_LEN));
	I += content_len + 2;
	return (1);
}
