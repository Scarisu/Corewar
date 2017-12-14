/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:06:50 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/12 00:31:36 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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
}

void	invalid_ind_val(t_asm *e)
{
	add_cont(e, &V_LINE, WHITE "Invalid argument, indirect value must be a ");
	add_cont(e, &V_LINE, WHITE "valid number or a label");
}

void	invalid_label_arg(t_asm *e)
{
	add_cont(e, &V_LINE, WHITE "BAD LABEL ARG");
}
