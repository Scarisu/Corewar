/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 06:21:47 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:15:06 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*a;
	char	*b;
	int		temp;
	int		nbrchar;

	nbrchar = ft_strlen(str);
	a = &str[0];
	b = &str[nbrchar] - 1;
	while (a < b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		a++;
		b--;
	}
	return (str);
}
