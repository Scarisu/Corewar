/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:31 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/08 20:48:08 by rlecart          ###   ########.fr       */
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
	jump_to_next(reg, tp[1] - reg->pc);
}

int		sti_norm2(t_corewar *d, t_reg *reg, t_need_norm *n)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		n->tpc[0] = n->ocp.p[i] == O_REG ? 1 : 2;
		n->r[i] = find_hexa(d->map, n->tpc[1], n->tpc[0]);
		if (n->ocp.p[i] == O_REG && n->r[i] >= 1 && n->r[i] <= 16)
			n->r[i] = reg->r[n->r[i] - 1];
		else if (n->ocp.p[i] == O_DIR && n->r[i] > 65536 / 2)
			n->r[i] -= 65536;
		else if (n->ocp.p[i] == O_IND)
			n->r[i] = find_ind_sti(d, reg, n->r[i]);
		else if (n->ocp.p[i] == O_REG && (n->r[i] < 1 || n->r[i] > 16)
				&& (false_cmd(d, reg, true)))
			return (-1);
		(n->tpc[1] += n->tpc[0]) >= MEM_SIZE ?
			n->tpc[1] -= MEM_SIZE : n->tpc[1];
	}
	return (0);
}

void	op_sti(t_corewar *d, t_reg *reg)
{
	t_ocp			ocp;
	t_need_norm		n;

	if (++reg->cycle == 25 && !(reg->cycle = 0))
	{
		n.i = -1;
		(n.tpc[1] = reg->pc + 1) >= MEM_SIZE ? n.tpc[1] -= MEM_SIZE : n.tpc[1];
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[n.tpc[1]])) &&
				(false_cmd(d, reg, true)))
			return ;
		(++n.tpc[1]) >= MEM_SIZE ? n.tpc[1] -= MEM_SIZE : n.tpc[1];
		ft_memcpy(n.ocp.p, ocp.p, 3 * sizeof(int));
		if (!(sti_norm2(d, reg, &n)))
			sti_norm(n.tpc, reg, n.r, d);
	}
}
