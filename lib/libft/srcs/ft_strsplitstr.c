/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:22:36 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:15:27 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplitstr(char const *s, char c)
{
	int		i;
	char	**str;

	i = 0;
	str = NULL;
	if (!(str = ft_strsplit(s, c)))
		return (NULL);
	while (str[i])
	{
		str[i] = ft_strjoin_clean_char(&str[i], c);
		i++;
	}
	return (str);
}
