/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 01:39:33 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:14:43 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (lil[0] == '\0')
		return (char*)(big);
	while (big[i] != '\0')
	{
		j = i;
		k = 0;
		while (big[j] == lil[k] && j < (int)len)
		{
			j++;
			k++;
			if (lil[k] == '\0')
				return (char*)(&big[i]);
		}
		i++;
	}
	return (NULL);
}
