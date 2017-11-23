/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:08:22 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:07:41 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ptr;

	ptr = NULL;
	if (lst && f)
	{
		ptr = f(lst);
		ptr->next = lst->next ? ft_lstmap(lst->next, f) : NULL;
	}
	return (ptr);
}
