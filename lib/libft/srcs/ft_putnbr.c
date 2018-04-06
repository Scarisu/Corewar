/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:22:28 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:09:42 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n <= 2147483647 && n >= -2147483648)
	{
		if (n < 0)
		{
			if (n == -2147483648)
				return (ft_putstr("-2147483648"));
			ft_putchar('-');
			n = n * -1;
		}
		if (n <= 9)
			ft_putchar(n + '0');
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}