/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:56:24 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/13 23:36:05 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <verbos.h>
# define BUFF e->champ.buff[0]
# define I e->verbos.i

typedef struct s_verbos	t_verbos;
typedef struct s_label	t_label;
typedef struct s_valid	t_valid;
typedef struct s_champ	t_champ;
typedef struct s_asm	t_asm;

struct			s_verbos
{
	int			i;
	int			nb_error;
	int			nb_line;
	int			len_arrow;
	int			line_left;
	char		*cmd_invalid;
	void		(*tab[12])(t_asm *);
};

struct			s_label
{
	int			coo[2];
	char		*name;
	t_label		*next;
};

struct			s_valid
{
	int			name_done;
	int			comment_done;
	char		*name;
	char		*prev;
	char		*comment;
	t_label		*label;
	t_label		*label_start;
	t_label		*check;
	t_label		*check_start;
};

struct			s_champ
{
	int			fd;
	char		buff[1];
	char		*all;
	char		*line;
	char		*file_path;
	char 		*file_name;
	t_valid		valid;
};

struct			s_asm
{
	t_champ		champ;
	t_verbos	verbos;
	int			(*tab[5])(t_asm *, char *);
};

void	usage(t_asm *e, int argc, char *av);
void	error(t_asm *e, int err);
void	set_data(t_asm *e);
t_label	*set_label(t_asm *e, int coo[2]);
void	set_ptrft(t_asm *e);
int		get_line(t_asm *e, char **line);
void	clean(t_asm *e);
void	clean_label(t_label *l);
void	check_line(t_asm *e);
int		save_name(t_asm *e, char *line);
int		verbos(t_asm *e, int err);
int		valid_name(char *name);
int		valid_label(char *name);
void	print_pos(t_asm *e, int err);
void	adapt_line(t_asm *e, char *line);
void	arrow(t_asm *e);
void	nb_error(t_asm *e);
void	missing_data(t_asm *e);
int		save_comment(t_asm *e, char *line);

int		skip_tab(t_asm *e, char *line);
int		cmd_name(t_asm *e, char *line);
int 	cmd_comment(t_asm *e, char *line);
int 	cmd_check(t_asm *e, char *line);
int		ins_label(t_asm *e, char *line);

void	name_exist(t_asm *e);
void	syntax(t_asm *e);
void	name_len(t_asm *e);
void	invalid_name(t_asm *e);
void	name_diff_file(t_asm *e);
void	invalid_char(t_asm *e);
void	print_invalid_char(int nb_inv, int nb_uni, char inv[31]);
void	comment_exist(t_asm *e);
void	comment_len(t_asm *e);
void	missing_name(t_asm *e);
void	missing_comment(t_asm *e);
void	invalid_command(t_asm *e);
void	invalid_label(t_asm *e);

#endif
