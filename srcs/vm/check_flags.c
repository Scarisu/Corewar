/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:54:06 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/16 07:15:25 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		check_dump(int ac, char **av, t_corewar *ret, int *i)
{
	if (*i + 1 < ac && (ft_c_atoi(av[*i + 1])) > 0)
		ret->dump = ft_c_atoi(av[(*i)++ + 1]);
	else
		error(0, NULL);
}

void		check_n(int ac, char **av, t_corewar *ret, int *(i[2]))
{
	int		tmp;

	tmp = ft_c_atoi(av[*(i[0]) + 1]);
	if (*(i[0]) + 2 < ac && tmp > 0 && tmp <= 4 &&
		(ft_strequ(".cor", &av[*(i[0]) + 2][ft_strlen(av[*(i[0]) + 2]) - 4])))
	{
		if (++*(i[1]) < 4)
		{
			if ((ft_al_exist(ret->numbers, tmp, 4)))
				error(0, NULL);
			ret->numbers[*(i[1])] = tmp;
			ret->champs_path[*(i[1])] = av[*(i[0]) + 2];
		}
		else
			error(0, NULL);
		*(i[0]) += 2;
	}
	else
		error(0, NULL);
}

void		check_cor(char **av, t_corewar *ret, int *i, int *j)
{
	if (++(*j) < 4)
	{
		ret->numbers[*j] = -1;
		ret->champs_path[*j] = av[*i];
	}
	else
		error(0, NULL);
}
