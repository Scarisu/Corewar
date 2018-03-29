/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:39:21 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/29 08:59:51 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

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
	return (counter > 1 ? true : false);
}

void	jump_to_next(t_corewar *d, t_reg *reg, int o, bool fork)
{
	if (!fork && !(is_anybody_here(d, reg->pc)))
		d->colors[reg->pc] -= 5;
	reg->pc += o;
	true_pc(&reg->pc);
//	while (reg->pc >= MEM_SIZE || reg->pc < 0)
//	{
//		if (reg->pc >= MEM_SIZE)
//			reg->pc -= MEM_SIZE;
//		else if (reg->pc < 0)
//			reg->pc += MEM_SIZE;
//	}
	if (!(is_anybody_here(d, reg->pc)))
		d->colors[reg->pc] += 5;
	//d->colors[reg->pc] += 5 >= 10 ? 0 : 5;
	//sleep(1);
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
