/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:21:27 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/23 02:45:10 by pbernier         ###   ########.fr       */
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
//	printf("LINE\n");
	while ((type_list[nb_params]))
	{
		if ((i = type_param(type_list[nb_params], line[I])) < 0)
			return (verbos(e, WRONG_ARG));
		if (!e->arg_value[i](e, line))
			return (0);
		if (nb_params + 1 < g_op_tab[opcode].nb_params && line[I] != ',')
			return (verbos(e, NOT_ENOUGHT_ARG));
		++I;
		++nb_params;
	}
	ft_memdel((void **)&e->verbos.opcode_name);
	//printf("..\n");
	//printf("[%s][%d]\n[%d][%d][%d][%d]\n\n",
			// g_op_tab[opcode].name,
			// g_op_tab[opcode].nb_params,
			// g_op_tab[opcode].type[0],
			// g_op_tab[opcode].type[1],
			// g_op_tab[opcode].type[2],
			// g_op_tab[opcode].type[3]
			// );
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
			if (first_char == limit[i])
				return (ret[i]);
			else if (!type)
				return (-1);
		}
	return (-1);
}
