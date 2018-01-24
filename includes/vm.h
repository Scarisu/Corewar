/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:04:11 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/24 13:20:17 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <corewar.h>
# include <ncurses.h>
# include <limits.h>

# define REG champs[i].reg

# define O_NONE		-1
# define O_DIR		0
# define O_IND		1
# define O_REG		2

typedef struct		s_reg			t_reg;
typedef struct		s_champ			t_champ;
typedef struct		s_corewar		t_corewar;
typedef struct		s_ocp			t_ocp;
typedef struct		s_need_ocp		t_need_ocp;

struct				s_need_ocp
{
	int				i;
	int				j;
	int				j2;
	int				tmp2;
	char			*tmp;
};

struct				s_ocp
{
	int				p[3];
};

struct				s_reg
{
	int				n;
	int				pc;
	int				cycle;
	char			carry;
	unsigned char	r[REG_NUMBER][REG_SIZE];
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
	int				cycle;
	int				cycle_tmp;
	int				max_checks;
	int				cycle_delta;
	int				cycle_to_die;
	int				nbr_live_all;
	int				last_live_call;
	int				numbers[4];
	int				*colors;
	bool			flag_v;
	char			*map;
	char			*(champs_path[4]);
	void			(*opcodes[17])(t_champ *, t_corewar *, t_reg *);
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
void				init_opcodes(t_corewar *d);

void				battle(t_champ *champs, t_corewar *d);

void				display(char *map, int *colors, t_corewar *d);
void				display_map(char *map, int *colors, t_corewar *d);
void				display_champs_color(int color);

void				game(t_champ *champs, t_corewar *d, char *map);
void				end_game(t_champ *champs, t_corewar *d);

void				op_null(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_live(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_ld(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_st(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_add(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_sub(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_and(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_or(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_xor(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_zjmp(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_ldi(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_sti(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_fork(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_lld(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_lldi(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_lfork(t_champ *champs, t_corewar *d, t_reg *reg);
void				op_aff(t_champ *champs, t_corewar *d, t_reg *reg);

void				jump_to_next(t_corewar *d, t_reg *reg, int o);
t_ocp				find_ocp(unsigned char ocp);

#endif
