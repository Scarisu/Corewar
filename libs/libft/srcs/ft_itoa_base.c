/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:51:01 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/15 05:39:59 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_itoa_base(unsigned int value, int base, char *basestr)
{
	char	*tmp;
	size_t	i;
	size_t	size;

	size = ft_intlen_base(value, base);
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	tmp[size] = '\0';
	if (!value)
		tmp[0] = '0';
	i = size - 1;
	while (value)
	{
		tmp[i] = basestr[value % base];
		value = value / base;
		i--;
	}
	return (tmp);
}
