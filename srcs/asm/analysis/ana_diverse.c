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
	if (line[I] && line[I] == COMMENT_CHAR)
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
	while (line[cmd_len] && line[cmd_len] != ' '
		&& line[cmd_len] != '\n' && line[cmd_len] != COMMENT_CHAR)
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

void	put_bin(t_asm *e, int **bin, int *add, size_t len_add)
{
	size_t	l[2];
	size_t	len_bin;
	int		*final;

	if ((e->verbos.nb_error))
		return ;
	len_bin = 0;
	len_bin = (bin == &e->bin.head) ? e->bin.len_head : len_bin;
	len_bin = (bin == &e->bin.file) ? e->bin.len_file : len_bin;
	e->bin.len_head += (bin == &e->bin.head) ? len_add : 0;
	e->bin.len_file += (bin == &e->bin.file) ? len_add : 0;
	if (!(final = (int *)malloc(sizeof(int) * (len_bin + len_add))))
		error(e, MALLOC);
	ft_memcpy(l, (size_t[2]){0, 0}, sizeof(size_t[2]));
	while (l[0] < len_bin)
	{
		final[l[0]] = (*bin)[l[0]];
		++l[0];
	}
	ft_memdel((void **)bin);
	while (l[1] < len_add)
		final[l[0]++] = add[l[1]++];
	*bin = final;
}
