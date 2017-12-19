/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:04:11 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/19 09:47:09 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <corewar.h>

typedef struct		s_champ
{
	int				len;
	bool			alive;
	char			*name;
	char			*comment;
	char			*content;
}					t_champ;

typedef struct		s_corewar
{
	int				nbc;
	int				dump;
	int				numbers[4];
	char			*(champs_path[4]);
}					t_corewar;

t_corewar			check_all(int argc, char **argv);
void				error(int code);

t_champ				*get_all_champs(char **argv, t_corewar data);

void				battle(t_champ *champs, t_corewar data);

#endif
