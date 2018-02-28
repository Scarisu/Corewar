/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:42 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/28 07:21:56 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_and_loop(t_corewar *d, t_reg *reg, t_ocp o, int pc)
{
	int		i;
	int		r[3];
	int		len[2];

	i = -1;
	len[1] = 0;
	while (++i < 3)
	{
		len[0] = 1;
		if (o.p[i] == O_DIR && (len[0] = 4))
			r[i] = find_hexa(d->map, pc, len[0]);
		else if (o.p[i] == O_IND && (len[0] = 2))
		{
			if ((r[i] = find_hexa(d->map, pc, len[0])) > 65535 / 2)
				r[i] -= 65535;
			r[i] = find_hexa(d->map, pc + ((r[i] - len[0] - 1) % IDX_MOD), len[0] + 2);
		}
		else
			r[i] = d->map[pc] - 1;
		(pc += len[0]) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		len[1] += len[0];
	}
	reg->r[r[2]] = r[0] & r[1];
	reg->carry = !reg->r[r[2]] ? 1 : 0;
	jump_to_next(d, reg, len[1] + 2, false);
}

void	op_and(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		pc;
	t_ocp	o;

	(void)champs;
	if (++reg->cycle == 7 && !(reg->cycle = 0))
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		o = find_ocp(d->map[pc]);
		if (!valid_ocp(o) && (false_command(d, reg, true)))
			return ;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		op_and_loop(d, reg, o, pc);
	}
}
