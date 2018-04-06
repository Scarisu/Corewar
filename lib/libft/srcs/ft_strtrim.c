/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:26:18 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:15:50 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_is_fws(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}

static int		ft_strlen_wws(const char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	while (str[i])
	{
		count++;
		i++;
	}
	i--;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	{
		count--;
		i--;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	str = NULL;
	i = 0;
	j = 0;
	if (s)
	{
		if (ft_check_is_fws(s) == 1 && s[0] != '\0')
			return (ft_strnew(0));
		len = ft_strlen_wws(s);
		if (!(str = ft_strnew(len)))
			return (NULL);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (s[i] && j < len)
			str[j++] = s[i++];
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
