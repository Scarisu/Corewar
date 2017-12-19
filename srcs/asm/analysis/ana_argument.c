/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:21:27 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/12 01:05:56 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		check_param(t_asm *e, t_enco *i, char *line)
{
	int	ret;

	if (!skip_tab(e, line))
		return (verbos(e, NEED_ARG));
	while ((g_op_tab[i->opcode - 1].type[i->nb_arg]))
	{
		i->bin_arg <<= 2;
		while (line[I] == ' ')
			++I;
		if ((ret = type_param(g_op_tab[i->opcode - 1].type[i->nb_arg], line[I])) < 0)
			return (verbos(e, WRONG_ARG));
		i->bin_arg += ret + 1;
		if ((ret == 0 && !arg_reg(e, line, &i->arg[i->nb_arg])) ||
			(ret != 0 && !arg_val(e, line, &i->arg[i->nb_arg], ret)))
			return (0);
		while (line[I] == ' ')
			++I;
		if (i->nb_arg + 1 < g_op_tab[i->opcode - 1].nb_params && line[I] != ',')
			return (verbos(e, NOT_ENOUGHT_ARG));
		++I;
		++i->nb_arg;
	}
	e->enco->bin_arg <<= (2 * (4 - i->nb_arg));
	return (0);
}

int		type_param(int type, char first_char)
{
	int		i;
	int		ret[3];
	int		type_exist[3];
	char	limit[3];

	i = -1;
	ft_memcpy(ret, (int[3]){2, 1, 0}, sizeof(int[3]));
	ft_memcpy(type_exist, (int[3]){T_IND, T_DIR, T_REG}, sizeof(int[3]));
	ft_memcpy(limit, (char[3]){LABEL_CHAR, DIRECT_CHAR, 'r'}, sizeof(char[3]));
	while (++i < 3)
		if (type >= type_exist[i])
		{
			type -= type_exist[i];
			if (first_char == limit[i] ||
				(i == 0 && (
				(first_char >= '0' && first_char <= '9') ||
				first_char == '-')))
				return (ret[i]);
			else if (!type)
				return (-1);
		}
	return (-1);
}
