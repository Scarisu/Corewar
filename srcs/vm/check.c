/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 06:43:20 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/19 10:23:24 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int			c_atoi(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			error(0);
	return (ft_atoi(str));
}

void		check_dump(int ac, char **av, t_corewar *ret, int *i)
{
	if (*i + 1 < ac && (c_atoi(av[*i + 1])) > 0)
		ret->dump = c_atoi(av[(*i)++ + 1]);
	else
		error(0);
}

void		check_n(int ac, char **av, t_corewar *ret, int *(i[2]))
{
	if (*(i[0]) + 2 < ac &&
		(c_atoi(av[*(i[0]) + 1]) > 0) && (c_atoi(av[*(i[0]) + 1]) <= 4) &&
		(ft_strequ(".cor", &av[*(i[0]) + 2][ft_strlen(av[*(i[0]) + 2]) - 4])))
	{
		if (++*(i[1]) < 4)
		{
			ret->numbers[*(i[1])] = c_atoi(av[*(i[0]) + 1]);
			ret->champs_path[*(i[1])] = av[*(i[0]) + 2];
		}
		else
			error(0);
		*(i[0]) += 2;
	}
	else
		error(0);
}

void		check_cor(char **av, t_corewar *ret, int *i, int *j)
{
	if (++(*j) < 4)
	{
		ret->numbers[*j] = ft_min_val(ret->numbers, 4) + 1;
		ret->champs_path[*j] = av[*i];
	}
	else
		error(0);
}

t_corewar	check_all(int ac, char **av)
{
	int			i;
	int			j;
	t_corewar	ret;

	i = -1;
	j = -1;
	ret.nbc = 0;
	ret.dump = 0;
	ft_memcpy(ret.numbers, (int[4]){-1, -1, -1, -1}, 4);
	while (++i < ac)
	{
		if ((ft_strequ("-dump", av[i])))
			check_dump(ac, av, &ret, &i);
		else if ((ft_strequ("-n", av[i])))
			check_n(ac, av, &ret, (int*[2]){&i, &j});
		else if (ft_strequ(".cor", &av[i][ft_strlen(av[i]) - 4]))
			check_cor(av, &ret, &i, &j);
		else
			error(0);
	}
	ret.nbc = j + 1;
	if (!ret.nbc)
		error(0);
	return (ret);
}
