/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:06:50 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/17 14:24:08 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	invalid_reg(t_asm *e)
{
	ft_memdel((void **)&e->verbos.opcode_name);
	ft_putstr_fd(WHITE "Invalid register, must be a positive number ", 2);
	ft_putstr_fd("lower or equal to ", 2);
	ft_putnbr_fd(REG_NUMBER, 2);
	(void)e;
}

void	invalid_arg_label(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.check->name)) > 30)
		e->verbos.len_arrow = 30;
	ft_memdel((void **)&e->champ.valid.check->name);
	ft_putstr_fd(WHITE "Label can't be null and ", 2);
	ft_putstr_fd("must only contain {" GREY LABEL_CHARS WHITE "}", 2);
}

void	invalid_dir(t_asm *e)
{
	(void)e;
}
