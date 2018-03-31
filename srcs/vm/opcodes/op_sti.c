/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:31 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/31 07:50:34 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		find_ind_sti(t_corewar *d, t_reg *reg, int param)
{
	if (param > 65536 / 2)
		param -= 65536;
	param = find_hexa(d->map, reg->pc + (param % IDX_MOD), 4);
	return (param);
}

void	sti_norm(int tp[2], t_reg *reg, int r[3], t_corewar *d)
{
	tp[0] = reg->pc + ((r[1] + r[2]) % IDX_MOD);
	true_pc(&tp[0]);
	put_hexa(d, reg->n, tp[0], r[0]);
	jump_to_next(d, reg, tp[1] - reg->pc, false);
}

void	op_sti(t_corewar *d, t_reg *reg)
{
	t_ocp			ocp;
	t_need_norm		n;

	if (++reg->cycle == 25 && !(reg->cycle = 0))
	{
		n.i = -1;
		(n.tp[1] = reg->pc + 1) >= MEM_SIZE ? n.tp[1] -= MEM_SIZE : n.tp[1];
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[n.tp[1]])) &&
				(false_cmd(d, reg, true)))
			return ;
		(++n.tp[1]) >= MEM_SIZE ? n.tp[1] -= MEM_SIZE : n.tp[1];
		while (++n.i < 3)
		{
			n.tp[0] = ocp.p[n.i] == O_REG ? 1 : 2;
			n.r[n.i] = find_hexa(d->map, n.tp[1], n.tp[0]);
			if (ocp.p[n.i] == O_REG && n.r[n.i] >= 1 && n.r[n.i] <= 16)
				n.r[n.i] = reg->r[n.r[n.i] - 1];
			else if (ocp.p[n.i] == O_IND)
				n.r[n.i] = find_ind_sti(d, reg, n.tp[1]);
			if (ocp.p[n.i] != O_REG && n.r[n.i] > 65536 / 2)
				n.r[n.i] -= 65536;
			(n.tp[1] += n.tp[0]) >= MEM_SIZE ? n.tp[1] -= MEM_SIZE : n.tp[1];
		}
		sti_norm(n.tp, reg, n.r, d);
	}
}
