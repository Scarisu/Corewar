/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:56:24 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/21 22:18:58 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <verbos.h>

# define BUFF e->champ.buff[0]
# define I e->verbos.i
# define NUMBER 1
# define LABEL 2

typedef struct s_verbos	t_verbos;
typedef struct s_label	t_label;
typedef struct s_valid	t_valid;
typedef struct s_champ	t_champ;
typedef struct s_asm	t_asm;

struct			s_label
{
	int			coo[2];
	int			*type;
	char		*print;
	t_label		*next;
};

struct			s_verbos
{
	int			i;
	int			nb_error;
	int			nb_line;
	int			len_arrow;
	int			line_left;
	int			opcode;
	int			reg_nbr;
	char		*cmd_invalid;
	char		*opcode_name;
	void		(*tab[20])(t_asm *);
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
	char		*line;
	char		*file_path;
	char 		*file_name;
	t_valid		valid;
};

struct			s_asm
{
	t_champ		champ;
	t_verbos	verbos;
	char		*head;
	char		*file;
	int			(*tab[6])(t_asm *, char *);
	int			(*arg_value[3])(t_asm *, char *);
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
int		exist_opcode(char *opcode);
int		type_param(int type, char first_char);

int		arg_reg_value(t_asm *e, char *line);
int		arg_dir_value(t_asm *e, char *line);
int		arg_label(t_asm *e, char *line);
int		arg_ind_value(t_asm *e, char *line);

int		skip_tab(t_asm *e, char *line);
int		cmd_name(t_asm *e, char *line);
int 	cmd_comment(t_asm *e, char *line);
int 	cmd_check(t_asm *e, char *line);
int		ins_label(t_asm *e, char *line);
int		ins_opcode(t_asm *e, char *line);

int		check_param(t_asm *e, int opcode, char *line);

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
void	invalid_opcode(t_asm *e);
void 	opcode_exist(t_asm *e);
void	need_arg(t_asm *e);
void	invalid_reg(t_asm *e);
void 	wrong_arg(t_asm *e);
void	not_enought_arg(t_asm *e);
void	invalid_arg_label(t_asm *e);
void	invalid_dir(t_asm *e);

#endif
