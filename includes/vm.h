/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:04:11 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/17 19:13:02 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# define REG champs[i].reg

# include <corewar.h>
# include <ncurses.h>

typedef struct		s_reg		t_reg;
typedef struct		s_champ		t_champ;
typedef struct		s_corewar	t_corewar;

struct				s_reg
{
	char			r[REG_NUMBER][REG_SIZE];
	char			*pc;
	char			carry;
	t_reg			*prev;
	t_reg			*next;
};

struct				s_champ
{
	int				len;
	int				nbr_live;
	bool			alive;
	char			*name;
	char			*comment;
	char			*content;
	t_reg			*reg;
};

struct				s_corewar
{
	int				nbc;
	int				dump;
	int				nbr_live_all;
	int				numbers[4];
	int				cycle;
	int				cycle_tmp;
	int				cycle_to_die;
	int				cycle_delta;
	int				max_checks;
	int				last_live_call;
	bool			flag_v;
	char			*(champs_path[4]);
};

void				check_dump(int ac, char **av, t_corewar *ret, int *i);
void				check_n(int ac, char **av, t_corewar *ret, int *(i[2]));
void				check_cor(char **av, t_corewar *ret, int *i, int *j);
t_corewar			check_all(int argc, char **argv);

void				error(int code, char *val);

t_champ				*get_all_champs(t_corewar data);

int					still_alive(t_champ *champs, int nbc);
int					live_counter(t_champ *champs, t_corewar *d);
void				reset_lives(t_champ *champs, int nbc);

int					*init_colors(t_champ *champs, t_corewar *d);
char				*init_battle(t_champ *champs, t_corewar *d);

void				battle(t_champ *champs, t_corewar *d);

void				display(char *map, int *colors, t_corewar *d);
void				display_map(char *map, int *colors, t_corewar *d);
void				display_champs_color(int color);

void				game(char *map);
void				end_game(t_champ *champs, t_corewar *d);

#endif
