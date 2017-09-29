/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:25:18 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/13 16:08:55 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen_base(int nbr, int base)
{
	int	len;

	len = 1;
	if (nbr < 0 && base == 10)
		len = 2;
	while ((nbr /= base))
		len++;
	return (len);
}
