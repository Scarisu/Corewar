/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:39:21 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/24 09:40:17 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	jump_to_next(t_corewar *d, t_reg *reg, int o)
{
	d->colors[reg->pc] -= 5;
	if ((reg->pc += o) == MEM_SIZE)
		reg->pc = 0;
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
	t_ocp	ret;
	t_need_ocp	e;

	ocp = 244;
	e.tmp2 = ocp * sizeof(int);
	e.tmp = ft_itoa_base(e.tmp2, 2, "01");
	ft_memset(ret.p, O_NONE, sizeof(int) * 3);
	if (ocp > 127)
		find_ocp_sup(e, &ret);
	else
		find_ocp_inf(e, &ret);
	return (ret);
}
