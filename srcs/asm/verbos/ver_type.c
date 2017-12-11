/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:06:50 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/11 23:53:09 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	invalid_reg(t_asm *e)
{
	char	*nbr;

	add_cont(e, &V_LINE, WHITE "Invalid register, must be a positive number ");
	add_cont(e, &V_LINE, "lower or equal to ");
	if (!(nbr = ft_itoa(REG_NUMBER)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
}

void	invalid_dir_val(t_asm *e)
{
	add_cont(e, &V_LINE, WHITE "Invalid argument, direct value must be a ");
	add_cont(e, &V_LINE, WHITE "valid number or a label");
	(void)e;
}
