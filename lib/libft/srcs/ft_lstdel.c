/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:51:56 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:06:58 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*ptr;

	ptr = *alst;
	while (ptr)
	{
		del(ptr->content, ptr->content_size);
		free(ptr);
		if (ptr->next)
			*alst = NULL;
		ptr = ptr->next;
	}
}
