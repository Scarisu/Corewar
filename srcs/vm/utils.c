/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:39:21 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 12:02:32 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		get_processes(int nbc, t_champ *champs)
{
	int		count;
	t_reg	*t;

	count = 0;
	while (--nbc >= 0)
	{
		t = champs[nbc].reg;
		while (t)
		{
			count++;
			t = t->next;
		}
	}
	return (count);
}

bool	is_anybody_here(t_corewar *d, int pc)
{
	int			i;
	int			counter;
	t_reg		*tmp;
	t_champ		*c;

	i = -1;
	counter = 0;
	c = d->champs;
	while (++i < d->nbc)
	{
		tmp = c[i].reg;
		while (tmp)
		{
			if (tmp->pc == pc)
				counter++;
			tmp = tmp->next;
		}
	}
	return (counter > 0 ? true : false);
}

void	jump_to_next(t_reg *reg, int o)
{
	reg->pc += o;
	true_pc(&reg->pc);
}

int		find_hexa(char *str, int i, int len)
{
	int				j;
	int				pc;
	int				ret;
	unsigned char	tab[4];

	j = -1;
	pc = i - 1;
	ret = 0;
	ft_bzero(tab, 4);
	true_pc(&pc);
	while (++j < len)
	{
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		tab[j] = str[pc];
	}
	j = -1;
	while (++j < len)
		ret += tab[j] << 8 * (len - j - 1);
	return (ret);
}

int		find_ocp(t_ocp *ret, unsigned char op, unsigned char ocp)
{
	int		i;
	int		j;

	i = 3;
	j = 0;
	ft_memset(ret->p, O_NONE, sizeof(int) * 3);
	while (--i >= 0)
	{
		if (ocp >> 2 * ++j & 1)
		{
			if (ocp >> (2 * j + 1) & 1)
				ret->p[i] = O_IND;
			else
				ret->p[i] = O_REG;
		}
		else
		{
			if (ocp >> (2 * j + 1) & 1)
				ret->p[i] = O_DIR;
			else
				ret->p[i] = O_NONE;
		}
	}
	return ((!(valid_ocp(ret, op - 1))) ? 0 : -1);
}
