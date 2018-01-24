/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:40 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/24 16:51:05 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_zjmp(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int				pc;
	unsigned char	param[2];

	(void)champs;
	if (++reg->cycle == 20)
	{
		if (reg->carry == 1)
		{
			ft_memset(param, 0, sizeof(param));
			(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			param[0] = d->map[pc];
			(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			param[1] = d->map[pc];
			//() >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			//pc = param[0] * 16 + param[1] * 16;
			pc = 0;
			pc *= 10 + (param[0] - '0');
			pc *= 10 + (param[1] - '0');
			printw("pc = %d\n", pc);
			printw("param[0] = %d\n", param[0]);
			printw("param[1] = %d\n", param[1]);
			printw("reg->pc = %d\n", reg->pc);
			refresh();
			while (1);
			jump_to_next(d, reg, pc);
			reg->cycle = 0;
		}
	}
}
