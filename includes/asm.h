/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:56:24 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/02 22:10:04 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define NB_ARG 1
# define EXTENTION 2
# define OPEN 3

# define READ 4

# define BUFF e->champ.buff[0]

typedef struct s_valid	t_valid;
typedef struct s_champ	t_champ;
typedef struct s_asm	t_asm;

struct			s_champ
{
	char		buff[1];
	char		*line;
	char		*all;
};

struct			s_asm
{
	char 		*name;
	int			fd;
	t_champ		champ;
};

void	usage(t_asm *e, int argc, char *argv);
void	error(t_asm *e, int err);
void	set(t_asm *e);
int		line(t_asm *e, char **line);

#endif
