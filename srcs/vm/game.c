/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:15:05 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/30 23:17:13 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		end_ww(t_corewar *d)
{
	if (d->flag_v)
		printw("\nAucun champion n'a gagne.\n");
	else
		ft_putstr("Aucun champion n'a gagne.\n");
	return (1);
}

void	end_game(t_champ *champs, t_corewar *d)
{
	int		i;

	i = 0;
	if (d->last_live_call <= 0 && end_ww(d))
		return ;
	if (d->flag_v)
	{
		printw("Le joueur %d(", i + 1);
		display_champs_color(i + 1);
		printw("%s", champs[d->last_live_call - 1].name);
		printw(") a gagne.\n\n");
		display_champs_color(0);
		printw("Appuyez sur une touche pour continuer.");
	}
	else
	{
		ft_putstr("Le joueur ");
		ft_putnbr(i + 1);
		ft_putstr("(");
		display_champs_color(i + 1);
		ft_putstr(champs[i].name);
		display_champs_color(0);
		ft_putstr(") a gagne.\n");
	}
}

t_reg	*get_first_reg(t_reg *reg)
{
	while (reg && reg->prev)
		reg = reg->prev;
	return (reg);
}

void	game(t_champ *champs, t_corewar *d, char *map)
{
	int		i;
	int		pc;
	t_reg	*t;

	i = d->nbc;
	while (--i >= 0)
	{
		t = champs[i].reg;
		while (champs[i].is_alive && t)
		{
			if ((pc = map[t->pc]) > 0 && pc <= 16)
				d->opcodes[pc](d, t);
			else
				d->opcodes[0](d, t);
			t = t->next;
		}
	}
}
