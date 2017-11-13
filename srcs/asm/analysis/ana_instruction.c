/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:35:29 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/13 19:00:39 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		ins_label(t_asm *e, char *line)
{
	int 	content_len;

	I = 0;
	if (!skip_tab(e, line) || !ft_strchr(line, LABEL_CHAR))
		return (1);
	content_len = I;
	while (line[content_len]
		&& line[content_len] != LABEL_CHAR)
	{
		if (line[content_len] == ' ')
			return (verbos(e, SYNTAX));
		if (!ft_strchr(LABEL_CHARS, line[content_len]))
			return (verbos(e, LABEL_INVALID_CHAR));
		++content_len;
	}
//	printf("[%s] - ", line);
	//printf("[%s][%d]\n", label, content_len);
	//ft_memdel((void **)&label);
	return (0);
}
