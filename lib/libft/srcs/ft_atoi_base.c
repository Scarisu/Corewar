/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 23:14:36 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/05 23:15:37 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		char_value(int c, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	return ((ft_strlen(str) == i) ? -1 : i);
}

int		ft_atoi_base(char *str, char *strbase)
{

	int		i;
	int		ret;
	int		neg;
	int		value;
	int		end;
	int		uni;

	i = 0;
	ret = 0;
	neg = 1;
	uni = 1;
	if (!strbase || !str)
		return (0);
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		neg = (str[i++] == '-' && neg != -1) ? -1 : neg;
	if ((end = ft_strlen(str) - 1) == i)
		return (0);
	while (end >= i && (value = char_value(str[end], strbase)) > -1)
	{
		ret += value * uni * neg;
		uni *= ft_strlen(strbase);
		end--;
	}
	if (end >= i)
		return (0);
	return (ret);
}
