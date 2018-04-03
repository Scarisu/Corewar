/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:27 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 15:13:48 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		find_ind_st(t_corewar *d, t_reg *reg, int pc, int r)
{
	int		param;

	if ((param = find_hexa(d->map, pc, 2)) > 65536 / 2)
		param -= 65536;
	param = reg->pc + (param % IDX_MOD);
	put_hexa(d, reg->n, param, reg->r[r - 1]);
	return (param);
}

void	op_st(t_corewar *d, t_reg *reg)
{
	int		param;
	int		rpc[2];
	t_ocp	ocp;

	param = 0;
	if (++reg->cycle == 5 && !(reg->cycle = 0))
	{
		(rpc[1] = reg->pc + 1) >= MEM_SIZE ? rpc[1] -= MEM_SIZE : rpc[1];
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[rpc[1]])) &&
				(false_cmd(d, reg, true)))
			return ;
		(++rpc[1]) >= MEM_SIZE ? rpc[1] -= MEM_SIZE : rpc[1];
		if ((rpc[0] = d->map[rpc[1]]) >= 1 && rpc[0] <= 16)
		{
			(++rpc[1]) >= MEM_SIZE ? rpc[1] -= MEM_SIZE : rpc[1];
			if (ocp.p[1] == O_IND)
				param = find_ind_st(d, reg, rpc[1], rpc[0]);
			else if ((param = d->map[rpc[1]]) == d->map[rpc[1]])
				reg->r[param - 1] = reg->r[rpc[0] - 1];
			rpc[1] = ocp.p[1] == O_IND ? 5 : 4;
			jump_to_next(reg, rpc[1]);
		}
		else
			false_cmd(d, reg, true);
	}
}
