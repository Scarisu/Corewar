/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:52:16 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:12:55 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char const *s1, char c)
{
	char	*str;
	int		len_s1;
	int		i;

	str = NULL;
	if (s1)
	{
		len_s1 = ft_strlen(s1);
		i = 0;
		if (!(str = ft_strnew(len_s1 + 1)))
			return (NULL);
		while (i < len_s1)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = c;
	}
	return (str);
}
