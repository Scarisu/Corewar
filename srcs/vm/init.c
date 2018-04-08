/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 07:52:05 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/08 20:47:34 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	init_values(t_corewar *d, char *map, t_champ *champs)
{
	d->cycle = 0;
	d->cycle_tmp = 0;
	d->nbr_live_all = 0;
	d->nbr_processes = 0;
	d->cycle_to_die = CYCLE_TO_DIE;
	d->cycle_delta = CYCLE_DELTA;
	d->max_checks = MAX_CHECKS;
	d->last_live_call = 0;
	d->map = map;
	d->champs = champs;
}

char	*init_battle(t_champ *champs, t_corewar *d)
{
	int		i;
	char	*map;

	i = -1;
	map = ft_memalloc(MEM_SIZE);
	while (++i < d->nbc)
	{
		ft_memcpy(&map[MEM_SIZE / d->nbc * i], champs[i].content,
				champs[i].len);
		REG = ft_memalloc(sizeof(t_reg));
		ft_bzero(REG->r, sizeof(REG->r));
		REG->r[0] = i - 1;
		REG->n = i + 1;
		REG->pc = MEM_SIZE / d->nbc * i;
		REG->cycle = 0;
		REG->live_counter = 0;
		REG->carry = 0;
		REG->prev = NULL;
		REG->next = NULL;
	}
	init_values(d, map, champs);
	return (map);
}

int		*init_colors(t_champ *champs, t_corewar *d)
{
	int		i;
	int		j;
	int		*colors;

	i = -1;
	colors = ft_memalloc(MEM_SIZE * sizeof(int));
	ft_memset(colors, 5, MEM_SIZE * sizeof(int));
	while (++i < d->nbc && (j = -1))
		while (++j < champs[i].len)
			colors[MEM_SIZE / d->nbc * i + j] = (int)(i + 1);
	return (colors);
}

void	init_opcodes(t_corewar *d)
{
	d->opcodes[0] = &op_null;
	d->opcodes[1] = &op_live;
	d->opcodes[2] = &op_ld;
	d->opcodes[3] = &op_st;
	d->opcodes[4] = &op_add;
	d->opcodes[5] = &op_sub;
	d->opcodes[6] = &op_and;
	d->opcodes[7] = &op_or;
	d->opcodes[8] = &op_xor;
	d->opcodes[9] = &op_zjmp;
	d->opcodes[10] = &op_ldi;
	d->opcodes[11] = &op_sti;
	d->opcodes[12] = &op_fork;
	d->opcodes[13] = &op_lld;
	d->opcodes[14] = &op_lldi;
	d->opcodes[15] = &op_lfork;
	d->opcodes[16] = &op_aff;
}
