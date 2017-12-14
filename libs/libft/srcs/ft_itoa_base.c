/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:51:01 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/14 02:46:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//int		int_len(int nb, int base)
//{
//	int		len;
//
//	len = 0;
//	if (nb < 0 && base == 10)
//		len++;
//	while ((nb /= 10) != 0)
//		len++;
//	return (++len);
//}
//
//char	*ft_itoa_base(int value, int base)
//{
//	int		len;
//	int		tmp;
//	char	*str;
//	char	*b;
//
//	if (!(b = ft_strdup("0123456789ABCDEF")))
//		return (NULL);
//	len = int_len(value, base);
//	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
//		return (0);
//	str[len--] = '\0';
//	while (value != 0)
//	{
//		tmp = (value % base);
//		if (tmp < 0)
//			tmp = -tmp;
//		str[len--] = b[tmp];
//		value = value / base;
//		if (len == 0 && value == 0)
//			str[len] = '-';
//	}
//	ft_strdel(&b);
//	return (str);
//}
char  *ft_itoa_base(unsigned int value, int base, char *basestr)
{
	size_t   size;
	size_t   i;
	char   *tmp;

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
