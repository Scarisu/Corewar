/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:39:21 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/16 21:32:14 by rlecart          ###   ########.fr       */
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
	while (reg->pc >= MEM_SIZE)
		reg->pc -= MEM_SIZE;
	if (!(is_anybody_here(d, reg->pc)))
		d->colors[reg->pc] += 5;
	//d->colors[reg->pc] += 5 >= 10 ? 0 : 5;
}

void	find_ocp_inf(t_need_ocp e, t_ocp *ret)
{
	e.i = -1;
	e.j = 3;
	e.j2 = 0;
	while (++e.i < 3)
	{
		if (e.tmp[e.j + e.j2] == '0')
		{
			if (e.tmp[e.j + e.j2 - 1] == '0')
				ret->p[e.i] = O_NONE;
			else
				ret->p[e.i] = O_REG;
		}
		else
		{
			if (e.tmp[e.j + e.j2 - 1] == '0')
				ret->p[e.i] = O_DIR;
			else
				ret->p[e.i] = O_IND;
		}
		if ((e.j -= 2) <= 0)
			if ((e.j2 += 6) > 6)
				break ;
	}
}

void	find_ocp_sup(t_need_ocp e, t_ocp *ret)
{
	e.i = -1;
	e.j = -2;
	while (++e.i < 3)
	{
		e.j += 2;
		if (e.tmp[e.j] == '0')
		{
			if (e.tmp[e.j + 1] == '0')
				ret->p[e.i] = O_NONE;
			else
				ret->p[e.i] = O_REG;
		}
		else
		{
			if (e.tmp[e.j + 1] == '0')
				ret->p[e.i] = O_DIR;
			else
				ret->p[e.i] = O_IND;
		}
	}
}

t_ocp	find_ocp(unsigned char ocp)
{
	t_ocp		ret;
	t_need_ocp	e;

	e.tmp2 = ocp * sizeof(int);
	e.tmp = ft_itoa_base(e.tmp2, 2);
	ft_memset(ret.p, O_NONE, sizeof(int) * 3);
	if (ocp > 127)
		find_ocp_sup(e, &ret);
	else
		find_ocp_inf(e, &ret);
	return (ret);
}

int		find_hexa(char *str, int i, int len)
{
	int				j;
	int				ret;
	unsigned char	tab[4];

	j = -1;
	ret = 0;
	ft_bzero(tab, 4);
	ft_memcpy(tab, &str[i], len);
	//printw("%x, %x, %x, %x\n", tab[0], tab[1], tab[2], tab[3]);
	//if (len == 2)
	//{
	//	tab[2] = tab[0];
	//	tab[3] = tab[1];
	//	ft_bzero(tab, 2);
	//}
	while (++j < len)
		ret += tab[j] << 8 * (len - j - 1);
//	if (len == 2)
//		ret = ret >> 16;
	return (ret);
}
