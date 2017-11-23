/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:58:26 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:08:31 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	src_cpy = (unsigned char*)src;
	dst_cpy = (unsigned char*)dst;
	while (n-- > 0)
		*dst_cpy++ = *src_cpy++;
	return (dst);
}
