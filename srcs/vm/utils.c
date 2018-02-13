/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:39:21 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/13 05:13:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	jump_to_next(t_corewar *d, t_reg *reg, int o, bool fork)
{
	if (!fork)
		d->colors[reg->pc] -= 5;
	reg->pc += o;
	while (reg->pc >= MEM_SIZE)
		reg->pc -= MEM_SIZE;
	d->colors[reg->pc] += 5;
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
	printw("%x, %x, %x, %x\n", tab[0], tab[1], tab[2], tab[3]);
	while (++j < len)
	{
		ret += tab[j] << 8 * (len - j - 1);
		printw("v = %x\n", tab[j]);
		printw("f = %x\n\n", ret << 8 * (j - 1));
		//ret <<= 8;
	}
	//ret >>= 8;
	//ft_memcpy(&ret, tab, sizeof(char) * len);
	printw("t = %d\n", ret);
	printw("t# = %x\n", ret);
	printw("tt = %d\n", 0xfd7f2180);
	refresh();
	while (1);
	return (ret);
}

/*int		find_hexa2(char *str, int i, int len)
{
	int		j;
	int		ret;
	char	*tab[len + 1];
	char	*tmp;
	char	*tmp2;

	j = -1;
	while (++j < len || (!(tab[j] = NULL) && (tmp = ft_strnew(0)) && !(j = -1)))
	{
		tab[j] = ft_itoa_base(str[i], 16);
		printw(">>%d<<\n", str[i]);
		printw(">%s<\n\n", tab[j]);
		i = i + 1 >= MEM_SIZE ? 0 : i + 1;
	}
	while (++j < len || !(ret = ft_atoi_base(tmp, "0123456789abcdef")))
	{
		tmp2 = ft_strjoin(tmp, tab[j]);
		ft_strdel(&tmp);
		tmp = tmp2;
	}
	ft_strdel(&tmp);
	printw("ret = %d\n", ret);
	refresh();
	while (1);
	return (ret);
}*/
