/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:58 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 15:19:28 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		find_ind_ldi(t_corewar *d, t_reg *reg, int param)
{
	if (param > 65536 / 2)
		param -= 65536;
	param = find_hexa(d->map, reg->pc + (param % IDX_MOD), 2);
	return (param);
}

void	ldi_norm(int tpc[2], t_reg *reg, int r[3], t_corewar *d)
{
	tpc[0] = reg->pc + ((r[0] + r[1]) % IDX_MOD);
	true_pc(&tpc[0]);
	reg->carry = 0;
	if (r[2] >= 1 && r[2] <= 16)
	{
		reg->r[r[2] - 1] = find_hexa(d->map, tpc[0], 4);
		reg->carry = !reg->r[r[2] - 1] ? 1 : 0;
	}
	jump_to_next(reg, tpc[1] - reg->pc);
}

void	op_ldi(t_corewar *d, t_reg *reg)
{
	int		i;
	int		tpc[2];
	int		r[3];
	t_ocp	ocp;

	if (++reg->cycle == 25 && !(reg->cycle = 0))
	{
		i = -1;
		(tpc[1] = reg->pc + 1) >= MEM_SIZE ? tpc[1] -= MEM_SIZE : tpc[1];
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[tpc[1]])) &&
				(false_cmd(d, reg, true)))
			return ;
		(++tpc[1]) >= MEM_SIZE ? tpc[1] -= MEM_SIZE : tpc[1];
		while (++i < 3)
		{
			tpc[0] = ocp.p[i] == O_REG ? 1 : 2;
			r[i] = find_hexa(d->map, tpc[1], tpc[0]);
			if (i < 2 && ocp.p[i] == O_REG && r[i] >= 1 && r[i] <= 16)
				r[i] = reg->r[r[i] - 1];
			else if (i < 2 && ocp.p[i] == O_REG && (false_cmd(d, reg, true)))
				return ;
			else if (ocp.p[i] == O_IND)
				r[i] = find_ind_ldi(d, reg, r[i]);
			else if (ocp.p[i] == O_DIR && r[i] > 65536 / 2)
				r[i] -= 65536;
			(tpc[1] += tpc[0]) >= MEM_SIZE ? tpc[1] -= MEM_SIZE : tpc[1];
		}
		ldi_norm(tpc, reg, r, d);
	}
}
