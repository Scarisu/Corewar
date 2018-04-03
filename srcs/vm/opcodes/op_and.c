/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:42 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 15:10:04 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		find_ind_and(t_corewar *d, t_reg *reg, int pc, int len)
{
	int		param;

	if ((param = find_hexa(d->map, pc, len) > 65536 / 2))
		param -= 65536;
	param = find_hexa(d->map, reg->pc + (param % IDX_MOD), len);
	return (param);
}

void	op_and_loop(t_corewar *d, t_reg *reg, t_ocp ocp, int pc)
{
	int		i;
	int		r[3];
	int		len[2];

	i = -1;
	len[1] = 0;
	while (++i < 3)
	{
		len[0] = 1;
		if (ocp.p[i] == O_DIR && (len[0] = 4))
			r[i] = find_hexa(d->map, pc, len[0]);
		else if (ocp.p[i] == O_IND && (len[0] = 2))
			r[i] = find_ind_and(d, reg, pc, len[0]);
		else if (((r[i] = d->map[pc] - 1) < 0 || r[i] >= 16) &&
				(false_cmd(d, reg, true)))
			return ;
		else if (i < 2 && r[i] >= 0 && r[i] < 16)
			r[i] = reg->r[r[i]];
		(pc += len[0]) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		len[1] += len[0];
	}
	reg->r[r[2]] = r[0] & r[1];
	reg->carry = !reg->r[r[2]] ? 1 : 0;
	jump_to_next(reg, len[1] + 2);
}

void	op_and(t_corewar *d, t_reg *reg)
{
	int		pc;
	t_ocp	ocp;

	if (++reg->cycle == 7 && !(reg->cycle = 0))
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[pc])) &&
				(false_cmd(d, reg, true)))
			return ;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		op_and_loop(d, reg, ocp, pc);
	}
}
