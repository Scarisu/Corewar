/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:56:24 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 00:37:08 by pbernier         ###   ########.fr       */
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
	int			i;
	int			len;
	int			sw;
	char		*arrow;
	char		*prev;
};

struct			s_valid
{
	char		*name;
	char		*comment;
};

struct			s_champ
{
	int			fd;
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

void	usage(t_asm *e, int argc, char *argv);
void	error(t_asm *e, int err);
void	set(t_asm *e);
int		get_line(t_asm *e, char **line);
void	clean(t_asm *e);
void	check_line(t_asm *e, char **line);
int		name(t_asm *e, char *line);
int		verbos(t_asm *e, t_verbos *v, int err);

#endif
