/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 01:23:59 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/26 20:14:30 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = -1;
	if (ft_strlen(dst) < ft_strlen(src))
		return (NULL);
	while (src[++i])
		dst[i] = src[i];
	dst[i] = src[i];
	return (dst);
}
