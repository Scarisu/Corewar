/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:56:24 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/08 20:16:15 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <verbos.h>
# define BUFF e->champ.buff[0]
# define I e->verbos.i

typedef struct s_verbos	t_verbos;
typedef struct s_valid	t_valid;
typedef struct s_champ	t_champ;
typedef struct s_asm	t_asm;

struct			s_verbos
{
	int			nb_error;
	int			nb_line;
	int			i;
	int			sw;
	int			len_arrow;
	void		(*tab[5])(t_asm *);
};

struct			s_valid
{
	char		*name;
	char		*comment;
	char		*prev;
};

struct			s_champ
{
	int			fd;
	char		*file_path;
	char 		*file_name;
	char		buff[1];
	char		*line;
	char		*all;
	t_valid		valid;
};

struct			s_asm
{
	t_champ		champ;
	t_verbos	verbos;
};

void	usage(t_asm *e, int argc, char *av);
void	error(t_asm *e, int err);
void	set_data(t_asm *e);
void	set_ptr(t_verbos *v);
int		get_line(t_asm *e, char **line);
void	clean(t_asm *e);
void	check_line(t_asm *e, char **line);
int		cmd_name(t_asm *e, char *line);
int		check_name(t_asm *e, char *line);
int		verbos(t_asm *e, int err);
int		skip_tab(t_asm *e, char *line);
int		valid_name(char **name);
void	print_pos(t_asm *e);
void	adapt_line(t_asm *e, char *line);
void	arrow(t_asm *e);
void	nb_error(t_asm *e);

void	name_exist(t_asm *e);
void	syntax_name(t_asm *e);
void	invalid_name(t_asm *e);
void	name_diff_file(t_asm *e);
void	invalid_char(t_asm *e);

#endif
