/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 07:15:57 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:08:57 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cpy;
	unsigned int	c_cpy;

	b_cpy = b;
	c_cpy = (unsigned int)c;
	while (len-- != 0)
		*b_cpy++ = c_cpy;
	return (b);
}
