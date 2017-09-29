/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 04:16:05 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:08:16 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*s_cpy;
	size_t		i;

	s_cpy = (char*)s;
	i = -1;
	while (++i < n)
	{
		if (*(s_cpy + i) == (char)c)
			return (s_cpy + i);
	}
	return (NULL);
}
