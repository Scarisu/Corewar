/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 05:24:09 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:14:15 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1_cpy;
	char	*s2_cpy;

	s1_cpy = s1;
	s2_cpy = (char*)s2;
	while (*s1_cpy)
		s1_cpy++;
	while (*s2_cpy && (int)n-- > 0)
		*s1_cpy++ = *s2_cpy++;
	*s1_cpy = '\0';
	return (s1);
}
