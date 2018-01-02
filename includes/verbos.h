/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:20:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/12 00:32:28 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOS_H
# define VERBOS_H

# define MAX_LINE			100

/*
** color
*/
# define RESET				"\033[0m"
# define RED				"\033[38;5;1m"
# define RED_MINUS			"\033[38;5;9m"
# define GREEN_MINUS		"\033[38;5;10m"
# define GREY				"\033[38;5;8m"
# define WHITE				"\033[38;5;7m"
# define GRAS				"\033[1m"
# define PINK				"\033[35m"

/*
** error
*/
# define NB_ARG				1
# define USAGE				2
# define EXTENTION			3
# define OPEN_CHAMP			4
# define READ_CHAMP			5
# define MALLOC				6
# define CREATE				7

/*
** verbos
*/
# define NAME_EXIST			0
# define SYNTAX				1
# define NAME_LEN 			2
# define INVALID_CHAR		3
# define COMMENT_EXIST		4
# define COMMENT_LEN		5
# define INVALID_COMMANDE	6
# define INVALID_LABEL		7
# define OPCODE_EXIST		8
# define NEED_ARG			9
# define WRONG_ARG			10
# define TOO_MANY_ARG		11
# define INVALID_REG		12

# define INVALID_DIR_VAL	13
# define INVALID_IND_VAL	14
# define INVALID_LABEL_ARG	15
# define LABEL_MULTI_INIT	16
# define LABEL_EXIST		17
# define LABEL_USED			18
# define MISSING_NAME		19
# define MISSING_COMMENT	20

typedef struct s_frag		t_frag;
typedef struct s_verbos		t_verbos;

struct			s_frag
{
	int			coo[2];
	char		*print;
	t_frag		*next;
};

struct			s_verbos
{
	int			i;
	int			nb_error;
	int			nb_warning;
	int			nb_line;
	int			len_arrow;
	int			line_left;
	int			opcode;
	int			reg_nbr;
	char		*cmd_invalid;
	char		*opcode_name;
	t_label		*pars;
	t_label		*prev_pars;
	t_frag		*frag;
	t_frag		*frag_start;
	void		(*tab[21])(t_asm *);
};

int		verbos(t_asm *e, int err);

void	print_pos(t_asm *e, int err);
void	add_cont(t_asm *e, char **line, char const *add);

void		name_exist(t_asm *e);
void		syntax(t_asm *e);
void		name_len(t_asm *e);
void		invalid_char(t_asm *e);
void			print_invalid_char(t_asm *e, int nb_inv,
				int nb_uni, char inv[31]);

void		comment_exist(t_asm *e);
void		comment_len(t_asm *e);

void		invalid_command(t_asm *e);

void		invalid_label(t_asm *e);
void 		opcode_exist(t_asm *e);
void		need_arg(t_asm *e);
void 		wrong_arg(t_asm *e);
void		too_many_arg(t_asm *e);

void		invalid_reg(t_asm *e);
void		invalid_dir_val(t_asm *e);
void		invalid_ind_val(t_asm *e);
void		invalid_label_arg(t_asm *e);
void			adjust_arrow_arg(t_asm *e);

void		label_multi_init(t_asm *e);
void		label_exist(t_asm *e);
void		label_used(t_asm *e);

void		missing_name(t_asm *e);
void		missing_comment(t_asm *e);

void	adapt_line(t_asm *e, char *line);
void	arrow(t_asm *e);



# endif
