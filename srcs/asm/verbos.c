/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:25:27 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 01:47:13 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int	verbos(t_asm *e, t_verbos *v, int err)
{
	++v->nb_error;
	printf("verbos : [%d]\n", err);
	(void)e;
	(void)v;
	(void)err;
	return (0);
}
