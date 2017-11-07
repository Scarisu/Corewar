/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:18:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 01:46:30 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		get_line(t_asm *e, char **line)
{
	int		ret;
	int		size;

	size = 0;
	BUFF = 'A';
	if (!(*line = malloc(sizeof(char) * (size + 1))))
		error(e, MALLOC);
	(*line)[size] = '\0';
	while (BUFF != '\n')
	{
		if ((ret = read(e->champ.fd, e->champ.buff, 1)) == -1)
			error(e, READ_CHAMP);
		if (!ret || BUFF == 0)
			return (ret);
		ft_strjoin_clean_char(line, BUFF);
		++size;
	}
	return (size);
}

void	check_line(t_asm *e, char **line)
{
	int	sw;

	while ((e->verbos.len = get_line(e, line)))
	{
		sw = 1;
		sw = (sw) ? name(e, *line) : 0;
		//sw = (sw) ? comment(e *line) : 0;

		ft_strjoin_clean(&e->champ.all, line);
		ft_memdel((void **)line);
	}
}

int		name(t_asm *e, char *line)
{
	int		content_len;

	I = 0;
	while (line[I] == ' ' || line[I] == '\t')
		++I;
	if (!(ft_strstr(line,  NAME_CMD_STRING) == &(line)[I]))
		return (1);
	if ((e->champ.valid.name))
		return (verbos(e, &e->verbos, NAME_EXIST));
	I += ft_strlen(NAME_CMD_STRING);
	while (line[I] == ' ' || line[I] == '\t')
		++I;
	if (line[I] != '\"' && line[I] != '\'')
		return (verbos(e, &e->verbos, SYN_NAME));
	content_len = I + 1;
	while (line[content_len] && line[content_len] != line[I])
		++content_len;
	if (!line[content_len])
		return (verbos(e, &e->verbos, SYN_NAME));
	content_len -= I + 1;
	if (!(e->champ.valid.name = ft_strsub(line, I + 1, content_len)))
		error(e, MALLOC);
	if (!content_len/* || !valid_name(e->champ.valid.name)*/)
		return (verbos(e, &e->verbos, INVALID_NAME));
	//if (ft_strcmp(e->champ.file_name, e->champ.valid.name))
	//	return (verbos(e, &e->verbos, INVALID_NAME));
	I += content_len + 2;
	while (line[I] == ' ' || line[I] == '\t')
		++I;
	if (line[I] && line[I] != '\n')
		return (verbos(e, &e->verbos, INVALID_CHAR));
	printf("OK\n");
	exit(0);
	return (1);
}

/// \ : * ? " < > |
