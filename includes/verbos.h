/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:20:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 20:29:29 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOS_H
# define VERBOS_H

/*
** color
*/
# define RESET "\033[0m"
# define RED "\033[38;5;1m"
# define RED_MINUS "\033[38;5;9m"
# define GREEN_MINUS "\033[38;5;10m"
# define GREY "\033[38;5;8m"
# define WHITE "\033[38;5;7m"
# define GRAS "\033[1m"

/*
** error
*/
# define NB_ARG 1
# define EXTENTION 2
# define OPEN_CHAMP 3
# define READ_CHAMP 4
# define MALLOC 5

/*
** verbos
*/
# define NAME_EXIST 1
# define SYN_NAME 2
# define INVALID_NAME 3
# define NAME_DIFF_FILE 4
# define INVALID_CHAR 5

# endif