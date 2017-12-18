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
# define NUMBER 1
# define LABEL 2

# define LIVE 1
# define LD 2
# define ST 3
# define ADD 4
# define SUB 5
# define AND 6
# define OR 7
# define XOR 8
# define ZJMP 9
# define LDI 10
# define STI 11
# define FORK 12
# define LLD 13
# define LLDI 14
# define LFORK 15
# define AFF 16

typedef struct s_label	t_label;
typedef struct s_valid	t_valid;
typedef struct s_champ	t_champ;
typedef struct s_bin	t_bin;
typedef struct s_enco	t_enco;
typedef struct s_asm	t_asm;

# include <verbos.h>
# include <corewar.h>

struct			s_label
{
	int			coo[2];
	int			octets;
	char		*name;
	char		*line;
	int			type;
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
	int			*head;
	size_t		len_head;
	int			*file;
	size_t		len_file;
	int			op_pos;
	int			*arg;
	size_t		len_arg;
};

struct			s_enco
{
	char		*hexa;
	t_label		*arg_label;
	int			nbr;
	t_enco		*next;
};

struct			s_asm
{
	t_champ		champ;
	t_verbos	verbos;
	t_bin		bin;
	t_enco		*enco;
	t_enco		*enco_start;
	int			(*tab[6])(t_asm *, char *);
};


void	error(t_asm *e, int err);

void	set_data(t_asm *e);
t_label		*set_label(t_asm *e, int coo[2]);
t_frag		*set_frag(t_asm *e, int coo[2]);
t_enco		*set_enco(t_asm *e);
void 	set_ptrft(t_asm *e);
void 	set_ptrver(t_asm *e);

void	usage(t_asm *e, int argc, char *av);

void	put_bin(t_asm *e, int **bin, int *add, size_t len_add);

void	check_line(t_asm *e);
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
int				check_param(t_asm *e, int opcode, char *line);
int				type_param(int type, char first_char);
int					arg_reg(t_asm *e, char *line);
int					arg_val(t_asm *e, char *line, int type, int opcode);
int					arg_lab(t_asm *e, char *line, int type);
void			enco_arg(t_asm *e, int opcode, int bin_arg);


void	missing_data(t_asm *e);
void	label_mutli(t_asm *e, t_verbos *ver, t_valid *val);
void	set_file(t_asm *e);
int			exist_label(t_asm *e, t_label *exi, t_valid *val);
void	used_label(t_asm *e, t_valid *val);

int		print_verbos(t_verbos *v);
int		nb_error(t_verbos *v);
void	set_head(t_asm *e);
void 	create_cor(t_asm *e);

void	clean(t_asm *e);
void		clean_label(t_label *l);
void		clean_frag(t_frag *f);

#endif
