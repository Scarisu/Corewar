/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:04:11 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/11 23:14:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <corewar.h>

typedef struct		s_champ
{
	int				len;
	int				nbr_live;
	bool			alive;
	char			*name;
	char			*comment;
	char			*content;
}					t_champ;

typedef struct		s_corewar
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
	char			*(champs_path[4]);
}					t_corewar;

t_corewar			check_all(int argc, char **argv);
void				error(int code, char *val);

t_champ				*get_all_champs(t_corewar data);

void				battle(t_champ *champs, t_corewar *d);

#endif
