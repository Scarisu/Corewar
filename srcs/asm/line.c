/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:18:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/08 22:26:13 by pbernier         ###   ########.fr       */
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
		if (BUFF == '\t')
			BUFF = ' ';
		ft_strjoin_clean_char(line, BUFF);
		++size;
	}
	return (size);
}

void	check_line(t_asm *e, char **line)
{
	int	sw;

	while (get_line(e, line) && e->verbos.nb_error <= 10)
	{
		sw = 1;
		sw = (sw) ? cmd_name(e, *line) : sw;
		sw = (sw) ? cmd_comment(e, *line) : sw;
		ft_memdel((void **)&e->champ.valid.prev);
		e->champ.valid.prev = ft_strdup(*line);
		ft_strjoin_clean(&e->champ.all, line);
		ft_memdel((void **)line);
		++e->verbos.nb_line;
	}
	ft_memdel((void **)&e->champ.valid.prev);
	ft_memdel((void **)line);
}

int		skip_tab(t_asm *e, char *line)
{
	while (line[I] == ' ')
		++I;
	if (line[I] == COMMENT_CHAR)
	{
		I += (I != 0) ? -1 : 0;
		return (0);
	}
	return (1);
}
