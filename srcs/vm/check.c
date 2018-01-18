/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 06:43:20 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/17 22:47:40 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		rec_norm_cor(t_corewar *ret, int j)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = 0;
	ret->nbc = j + 1;
	if (!ret->nbc)
		error(0, NULL);
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
	ret.flag_v = false;
	ft_memcpy(ret.numbers, (int[4]){0, 0, 0, 0}, sizeof(int) * 4);
	while (++i < ac)
	{
		if ((ft_strequ("-dump", av[i])) && !ret.flag_v)
			check_dump(ac, av, &ret, &i);
		else if ((ft_strequ("-n", av[i])))
			check_n(ac, av, &ret, (int*[2]){&i, &j});
		else if (ft_strequ(".cor", &av[i][ft_strlen(av[i]) - 4]))
			check_cor(av, &ret, &i, &j);
		else if ((ft_strequ("-v", av[i])) && ret.dump == -1)
			ret.flag_v = true;
		else
			error(0, NULL);
	}
	rec_norm_cor(&ret, j);
	init_opcodes(&ret);
	return (ret);
}
