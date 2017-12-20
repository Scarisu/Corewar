/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 06:43:20 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/20 08:59:45 by rlecart          ###   ########.fr       */
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

void		rec_norm_cor(t_corewar *ret)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = 0;
	while (++i < ret->nbc)
	{
		while (ret->numbers[i] == -1)
		{
			++tmp;
			if (!(ft_al_exist(ret->numbers, tmp, 4)))
				ret->numbers[i] = tmp;
			else if (tmp > 4)
				error(0, NULL);
		}
	}
}

t_corewar	check_all(int ac, char **av)
{
	int			i;
	int			j;
	t_corewar	ret;

	i = -1;
	j = -1;
	ret.nbc = 0;
	ret.dump = -1;
	ft_memcpy(ret.numbers, (int[4]){0, 0, 0, 0}, sizeof(int) * 4);
	while (++i < ac)
	{
		if ((ft_strequ("-dump", av[i])))
			check_dump(ac, av, &ret, &i);
		else if ((ft_strequ("-n", av[i])))
			check_n(ac, av, &ret, (int*[2]){&i, &j});
		else if (ft_strequ(".cor", &av[i][ft_strlen(av[i]) - 4]))
			check_cor(av, &ret, &i, &j);
		else
			error(0, NULL);
	}
	ret.nbc = j + 1;
	if (!ret.nbc)
		error(0, NULL);
	rec_norm_cor(&ret);
	return (ret);
}
