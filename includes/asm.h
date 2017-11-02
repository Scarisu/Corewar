/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:56:24 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/02 21:20:35 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define NB_ARG 1
# define EXTENTION 2
# define FD 3

typedef struct s_asm	t_asm;

struct			s_asm
{
	char 		*name;
	int			fd;
};

void	usage(t_asm *e, int argc, char *argv);
void	error(t_asm *e, int err);
int		line(t_asm *e, char **line);

#endif
