/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 06:32:51 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:07:28 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list **alst)
{
	t_list		*ptr;

	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
