/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_diverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:11:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/29 19:56:44 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	invalid_command(t_asm *e)
{
	int		start;
	char	tmp[2];

	start = 0;
	if ((e->verbos.len_arrow = ft_strlen(e->verbos.cmd_invalid)) > 30)
		e->verbos.len_arrow = 30;
	add_cont(e, &V_LINE, WHITE "Command \"" GREY);
	while (e->verbos.cmd_invalid[start] && start < 30)
	{
		ft_memcpy(tmp, (char[2]){e->verbos.cmd_invalid[start++], '\0'},
			sizeof(char[2]));
		add_cont(e, &V_LINE, tmp);
	}
	if (start == 30 && ft_strlen(e->verbos.cmd_invalid) > 30)
		add_cont(e, &V_LINE, WHITE " ...");
	ft_memdel((void **)&e->verbos.cmd_invalid);
	add_cont(e, &V_LINE, WHITE "\" doesn't exist");
}

void	syntax(t_asm *e)
{
	e->verbos.len_arrow = 0;
	add_cont(e, &V_LINE, WHITE "Syntax error");
}

void	invalid_char(t_asm *e)
{
	int		i;
	int		nb_inv;
	int		nb_uni;
	char	inv[6];

	i = I;
	nb_inv = 0;
	nb_uni = 0;
	ft_bzero(inv, 6);
	while (e->champ.line[i] && (i - (I + 1)) < 30
		&& e->champ.line[i] != '\n' && e->champ.line[i] != ' '
		&& e->champ.line[i] != COMMENT_CHAR)
	{
		if (!((int)e->champ.line[i] <= 127 && e->champ.line[i] >= 0))
			++nb_uni;
		else if (!ft_strchr(inv, e->champ.line[i]) && ++nb_inv < 6)
			inv[ft_strlen(inv)] = e->champ.line[i];
		++i;
	}
	e->verbos.len_arrow = i - (I + 1) - (nb_uni / 2);
	print_invalid_char(e, nb_inv, nb_uni, inv);
}

void	print_invalid_char(t_asm *e, int nb_inv, int nb_uni, char inv[31])
{
	int		print;
	char	tmp[2];

	print = -1;
	add_cont(e, &V_LINE, WHITE "Invalid character");
	nb_inv > 1 ? add_cont(e, &V_LINE, "s") : 0;
	add_cont(e, &V_LINE, ": {" GREY);
	while (inv[++print])
	{
		(print) ? add_cont(e, &V_LINE, WHITE "," GREY) : 0;
		ft_memcpy(tmp, (char[2]){inv[print], '\0'}, sizeof(char[2]));
		add_cont(e, &V_LINE, tmp);
	}
	if ((print) && (nb_uni))
		add_cont(e, &V_LINE, WHITE ", ");
	else if (ft_strlen(inv) < (size_t)nb_inv)
		add_cont(e, &V_LINE, WHITE " ");
	if ((nb_uni) || ft_strlen(inv) < (size_t)nb_inv)
		add_cont(e, &V_LINE, WHITE "...");
	add_cont(e, &V_LINE, WHITE "}");
}

void	champ_too_long(t_asm *e)
{
	char	*size;

	add_cont(e, &V_LINE, WHITE "Invalid champion's size {" GREY);
	if (!(size = ft_itoa(e->bin.len_file)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, size);
	ft_memdel((void **)&size);
	add_cont(e, &V_LINE, WHITE "}, must be positive and under {" GREY);
	if (!(size = ft_itoa(CHAMP_MAX_SIZE)))
		error(e, MALLOC);
	add_cont(e, &V_LINE, size);
	ft_memdel((void **)&size);
	add_cont(e, &V_LINE, WHITE "}");
	add_cont(e, &V_LINE, RESET "\n");
}
