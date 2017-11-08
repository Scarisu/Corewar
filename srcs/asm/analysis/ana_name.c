/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:35:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/08 20:01:20 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		name(t_asm *e, char *line)
{
	int		content_len;

	I = 0;
	if (!skip_tab(e, line) ||
		!(ft_strstr(line,  NAME_CMD_STRING) == &(line)[I]))
		return (1);
	if ((e->champ.valid.name))
		return (verbos(e, NAME_EXIST));
	I += ft_strlen(NAME_CMD_STRING);
	if (!skip_tab(e, line) || (line[I] != '\"' && line[I] != '\''))
		return (verbos(e, SYNTAX_NAME));
	content_len = I + 1;
	while (line[content_len] && line[content_len] != line[I])
		++content_len;
	if (!line[content_len])
		return (verbos(e, SYNTAX_NAME));
	content_len -= I + 1;
	if (!(e->champ.valid.name = ft_strsub(line, I + 1, content_len)))
		error(e, MALLOC);
	if (!valid_name(&e->champ.valid.name))
		return (verbos(e, INVALID_NAME));
	if (ft_strcmp(e->champ.file_name, e->champ.valid.name))
		return (verbos(e, NAME_DIFF_FILE));
	I += content_len + 2;
	if (!skip_tab(e, line))
		return (0);
	if (line[I] && line[I] != '\n')
		return (verbos(e, INVALID_CHAR));
	return (0);
}

int		valid_name(char **name)
{
	int		i;
	char	invalid_char[10];

	i = -1;
	if (!ft_strlen(*name))
		return (0);
	ft_memcpy(invalid_char, (char[10]){"/\\:*?\"<>|\0"}, sizeof(char[10]));
	while ((*name)[++i])
		if (ft_strchr(invalid_char, (*name)[i]))
			return (0);
	return (1);
}
