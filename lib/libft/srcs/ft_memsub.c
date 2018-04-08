/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:31:27 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/01 02:00:10 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memsub(void *src, unsigned int start, unsigned int len)
{
	char			*src_tmp;
	char			*ret_tmp;
	void			*ret;
	unsigned int	i;

	i = -1;
	ret = ft_memalloc(len);
	src_tmp = src;
	ret_tmp = ret;
	while (++i < len)
		ret_tmp[i] = src_tmp[start + i];
	return (ret);
}
