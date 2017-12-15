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

int		check_param(t_asm *e, int opcode, char *line)
{
	int	bin_arg;
	int	nb_params;
	int	type_list[4];
	int	i;

	bin_arg = 0b00000000;
	nb_params = 0;
	if (!skip_tab(e, line))
		return (verbos(e, NEED_ARG));
	ft_memcpy(type_list, g_op_tab[opcode].type, sizeof(int[MAX_ARGS_NUMBER]));
	while ((type_list[nb_params]))
	{
		while (line[I] == ' ')
			++I;
		if ((i = type_param(type_list[nb_params], line[I])) < 0)
			return (verbos(e, WRONG_ARG));
		bin_arg += i + 1;
		if ((i == 0 && !arg_reg(e, line)) || (i != 0 && !arg_val(e, line, i)))
			return (0);
		while (line[I] == ' ')
			++I;
		if (nb_params + 1 < g_op_tab[opcode].nb_params && line[I] != ',')
			return (verbos(e, NOT_ENOUGHT_ARG));
		++I;
		++nb_params;
		bin_arg <<= 2;
	}
	enco_arg(e, opcode, bin_arg);
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

void	enco_arg(t_asm *e, int opcode, int bin_arg)
{
	//printf("[%lu]\n", 4 - e->bin.len_arg);

	if (opcode + 1 != 1 && opcode + 1 != 9 &&
		opcode + 1 != 15 && opcode + 1 != 16)
		put_bin(e, &e->bin.file, (int[1]){bin_arg}, 1);

	if (opcode + 1 == 1 || opcode + 1 == 2 || opcode + 1 == 6 ||
	  	opcode + 1 == 7 || opcode + 1 == 8 || opcode + 1 == 13)
	 	put_bin(e, &e->bin.file, (int[4]){} , 4 - e->bin.len_arg);

	put_bin(e, &e->bin.file, e->bin.arg, e->bin.len_arg);
	ft_memdel((void **)&e->bin.arg);
	e->bin.len_arg = 0;
	if (!(e->bin.arg = (int *)malloc(sizeof(int))))
		error(e, MALLOC);
	(void)opcode;
	(void)bin_arg;
}
