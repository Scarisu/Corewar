/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:56:01 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/20 16:17:09 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	name_exist(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(NAME_CMD_STRING) - 1) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Champion's name already set", 2);
	if ((e->champ.valid.name))
	{
		ft_putstr_fd(": \"" GREY, 2);
		ft_putstr_fd(e->champ.valid.name, 2);
		ft_putstr_fd(WHITE "\"", 2);
	}
}

void	invalid_name(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.name) + 1) > 30)
		e->verbos.len_arrow = 30;
	ft_memdel((void **)&e->champ.valid.name);
	ft_putstr_fd(WHITE "Champion's name can't be null ", 2);
	ft_putstr_fd("or contain { /\\:*?\"<>| }", 2);
}

void	name_diff_file(t_asm *e)
{
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.name) + 1) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Champion's name is different from ", 2);
	ft_putstr_fd("the orignal file: {\"" GREY, 2);
	ft_putstr_fd(e->champ.file_name, 2);
	ft_putstr_fd(WHITE "\", \"" GREY, 2);
	ft_putstr_fd(e->champ.valid.name, 2);
	ft_memdel((void **)&e->champ.valid.name);
	ft_putstr_fd(WHITE "\"}", 2);
}

void	name_len(t_asm *e)
{
	int start;

	start = 0;
	if ((e->verbos.len_arrow = ft_strlen(e->champ.valid.name) + 1) > 30)
		e->verbos.len_arrow = 30;
	ft_putstr_fd(WHITE "Champion's name too long {" GREY, 2);
	ft_putnbr_fd(ft_strlen(e->champ.valid.name), 2);
	ft_memdel((void **)&e->champ.valid.name);
	ft_putstr_fd(WHITE "}, max name len: {", 2);
	ft_putstr_fd(GREY, 2);
	ft_putnbr_fd(PROG_NAME_LENGTH, 2);
	ft_putstr_fd(WHITE "}", 2);
}

/*
** void	syntax(t_asm *e);
*/

/*
** void	invalid_char(t_asm *e);
*/
