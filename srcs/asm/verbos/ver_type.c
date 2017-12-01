/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:06:50 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/28 21:02:45 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	invalid_reg(t_asm *e)
{
	char	*nbr;

	nbr = NULL;
	ft_memdel((void **)&e->verbos.opcode_name);
	add_cont(e, &V_LINE, WHITE "Invalid register, must be a positive number ");
	add_cont(e, &V_LINE, "lower or equal to ");
	if (!(nbr = ft_itoa(REG_NUMBER)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, nbr);
	ft_memdel((void **)&nbr);
}

void	invalid_arg_label(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.check->name)) > 30)
		e->verbos.len_arrow = 30;
	ft_memdel((void **)&e->champ.valid.check->name);
	add_cont(e, &V_LINE, WHITE "Label can't be null and ");
	add_cont(e, &V_LINE, "must only contain {" GREY LABEL_CHARS WHITE "}");
}

void	invalid_dir(t_asm *e)
{
	(void)e;
}
