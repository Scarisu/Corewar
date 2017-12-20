/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:56:24 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/12 00:33:09 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define BUFF e->champ.buff[0]
# define I e->verbos.i
# define V_LINE e->verbos.frag->print

typedef struct s_champ	t_champ;
typedef struct s_valid	t_valid;
typedef struct s_label	t_label;
typedef struct s_bin	t_bin;
typedef struct s_enco	t_enco;
typedef struct s_arg	t_arg;
typedef struct s_asm	t_asm;

# include <verbos.h>
# include <corewar.h>

struct			s_label
{
	int			coo[2];
	int			octets;
	char		*name;
	char		*line;
	int			used;
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

struct			s_bin
{
	int			op_pos;
	int			*head;
	size_t		len_head;
	int			*file;
	size_t		len_file;
};

struct			s_arg
{
	int			arg_value;
	int			type;
	t_label		*arg_label;
};

struct			s_enco
{
	int			opcode;
	int			bin_arg;
	t_arg		arg[MAX_ARGS_NUMBER];
	int			nb_arg;
	t_enco		*next;
};

struct			s_asm
{
	int			flag;
	t_champ		champ;
	t_verbos	verbos;
	t_bin		bin;
	t_enco		*enco;
	t_enco		*enco_start;
	int			(*tab[6])(t_asm *, char *);
};


void	error(t_asm *e, int err);

void	init_all(t_asm *e);
void		set_champ(t_asm *e, t_champ *c);
t_label			*set_label(t_asm *e, int coo[2]);
void		set_verbos(t_asm *e, t_verbos *v);
t_frag			*set_frag(t_asm *e, int coo[2]);
void 			set_ptrver(t_verbos *v);
void		set_bin(t_asm *e, t_bin *b);
t_enco		*set_enco(t_asm *e);
void 		set_ptrft(t_asm *e);


void	usage(t_asm *e, int argc, char **av);
void		flag(t_asm *e, char *av);
void	put_bin(t_asm *e, int **bin, int *add, size_t len_add);

void	check_line(t_asm *e, t_verbos *v, t_champ *c);
int			get_line(t_asm *e, char **line);

int			skip_tab(t_asm *e, char *line);
int			cmd_name(t_asm *e, char *line);
int				save_name(t_asm *e, char *line);
int				valid_name(char *name);
int 		cmd_comment(t_asm *e, char *line);
int				save_comment(t_asm *e, char *line);
int 		cmd_check(t_asm *e, char *line);
int			ins_label(t_asm *e, char *line);
int				valid_label(char *name);
int			ins_opcode(t_asm *e, char *line);
int				exist_opcode(char *opcode);
int				check_param(t_asm *e, t_enco *i, char *line);
int				type_param(int type, char first_char);
int					arg_reg(t_asm *e, char *line, t_arg *arg);
int					arg_val(t_asm *e, char *line, t_arg *arg, int type);
int					arg_lab(t_asm *e, char *line, t_arg *arg, int type);
int				opcode_position(t_enco *i);

void	label_mutli(t_asm *e, t_verbos *ver, t_valid *val);
void		del_label_multi(t_asm *e, t_verbos *ver);
void	set_file(t_asm *e, t_enco *i);
int        set_shift(t_enco *i, int nb);
int			exist_label(t_asm *e, t_label *exi, t_valid *val, int shift);
void	used_label(t_asm *e, t_valid *val);

int		print_verbos(t_verbos *v);
void	set_head(t_asm *e);
void 	create_cor(t_asm *e);

void	clean(t_asm *e);
void		clean_label(t_label *l);
void		clean_frag(t_frag *f);
void		clean_enco(t_enco *e);

#endif
