/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:21:27 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/06 01:18:54 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		check_param(t_asm *e, int opcode, char *line)
{
	int	nb_params;
	int	type_list[4];
	int	i;

	nb_params = 0;
	if (!skip_tab(e, line))
		return (verbos(e, NEED_ARG));
	ft_memcpy(type_list, g_op_tab[opcode].type, sizeof(int[MAX_ARGS_NUMBER]));
	while ((type_list[nb_params]))
	{
		while (line[I] == ' ')
			++I;
		i = type_param(e, type_list[nb_params], line[I]);
		if (i < 0)
			return (verbos(e, WRONG_ARG));
		if (!e->arg_value[i](e, line))
			return (0);
		if (nb_params + 1 < g_op_tab[opcode].nb_params && line[I] != ',')
			return (verbos(e, NOT_ENOUGHT_ARG));
		++I;
		++nb_params;
	}
	ft_memdel((void **)&e->verbos.opcode_name);
	return (0);
}

int		type_param(t_asm *e, int type, char first_char)
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
				first_char == '-' || first_char == '+')))
			{
				e->size += (!e->verbos.nb_error) ? type_exist[i] : 0;
				return (ret[i]);
			}
			else if (!type)
				return (-1);
		}
	return (-1);
}
