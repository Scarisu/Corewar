/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:15:11 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/15 05:56:39 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int			get_nbc(char **argv)
{
	int		nbc;

	if ((nbc = ft_atoi(argv[0])) > MAX_PLAYERS)
		exit(-1);
	return (nbc);
}

char		*get_file(char *path, int *len)
{
	int		i;
	int		fd;
	char	tmp;
	char	*result;

	i = 0;
	fd = open(path, O_RDONLY);
	result = ft_strnew(0);
	while ((read(fd, &tmp, 1)))
	{
		result = ft_realloc(result, ++i + 1);
		result[i] = tmp;
	}
	close(fd);
	*len = i + 1;
	return (result);
}

void		get_head(t_champ *champs, int i)
{
	int		j;

	j = 0;
	while (!ft_isalnum(champs[i].content[j]))
		j++;
	champs[i].name = ft_strdup(&champs[i].content[j]);
	if ((j = ft_strlen(champs[i].name) + 5) > PROG_NAME_LENGTH - 5)
		exit(-1);
	while (!ft_isalnum(champs[i].content[j]))
		j++;
	champs[i].comment = ft_strdup(&champs[i].content[j]);
	if (ft_strlen(champs[i].comment) > COMMENT_LENGTH)
		exit(-1);
//	printf("%s\n", champs[i].name);
//	printf("%s\n", champs[i].comment);
}

t_champ		*get_all_champs(char **argv, int nbc)
{
	int			i;
	int			add;
	char		*tmp;
	t_champ		*champs;

	i = -1;
	add = PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + 1;
	champs = ft_memalloc(nbc * sizeof(t_champ));
	while (++i < nbc)
	{
		champs[i].content = get_file(argv[1 + i], &champs[i].len);
		get_head(champs, i);
		if ((champs[i].len -= add) > CHAMP_MAX_SIZE)
			exit(-1);
		tmp = ft_memsub(champs[i].content, add, champs[i].len);
		ft_strdel(&champs[i].content);
		champs[i].content = tmp;
		champs[i].alive = true;
	}
//	i = -1;
//	while (++i < champs[0].len)
//		printf("%d = %d\n", i, champs[0].content[i]);
	return (champs);
}
