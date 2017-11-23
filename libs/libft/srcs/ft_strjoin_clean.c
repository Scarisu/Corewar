/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:16:59 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/13 14:47:18 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_clean(char **s1, char **s2)
{
	size_t	l[2];
	char	*final;

	l[0] = (*s1) ? ft_strlen(*s1) : 0;
	l[1] = (*s2) ? ft_strlen(*s2) : 0;
	if (!(final = (char *)malloc(sizeof(char) * (l[0] + l[1] + 1))))
		return (NULL);
	final[l[0] + l[1]] = '\0';
	ft_memcpy(l, ((size_t[2]){-1, 0}), sizeof(size_t[2]));
	while ((*s1)[++l[0]])
		final[l[0]] = (*s1)[l[0]];
	ft_memdel((void **)s1);
	while ((*s2)[l[1]])
		final[l[0]++] = (*s2)[l[1]++];
	*s1 = final;
	return (*s1);
}
