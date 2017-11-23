/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:51:17 by rlecart           #+#    #+#             */
/*   Updated: 2017/11/23 07:20:13 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_ttoa(char **tab)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strnew(0);
	while (tab && tab[i])
		ret = ft_strjoin_clean(&ret, &tab[i++]);
//	ft_strtabdel(&tab);
	return (ret);
}
