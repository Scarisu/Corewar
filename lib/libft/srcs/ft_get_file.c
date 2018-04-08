/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:05:23 by rlecart           #+#    #+#             */
/*   Updated: 2017/11/23 06:50:50 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_get_file(char *file)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	*keep;
	char	**result;

	ret = 0;
	tmp = ft_strnew(1);
	keep = ft_strnew(0);
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	while ((ret = read(fd, tmp, 1)) > 0)
		keep = ft_strjoin_clean(&keep, &tmp);
	if (!(result = ft_strsplit(keep, '\n')))
		return (NULL);
	ft_strdel(&tmp);
	ft_strdel(&keep);
	if ((close(fd)) == -1)
		return (NULL);
	return (result);
}
