/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:09:05 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/15 00:09:06 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		create_cor(t_asm *e)
{
    int	fd;
	size_t i;

	add_cont(e, &e->champ.file_path, e->champ.file_name);
	add_cont(e, &e->champ.file_path, ".cor");
	if ((fd = open(e->champ.file_path,
		O_CREAT | O_RDWR | O_TRUNC, 0755)) < 2)
		error(e, CREATE);
    set_head(e);
	i = 0;
	while (i < e->len_head)
		ft_putchar_fd(e->head[i++], fd);
	i = 0;
	while (i < e->len_file)
		ft_putchar_fd(e->file[i++], fd);
	ft_putstr(e->champ.file_name);
	ft_putstr(".cor a bien été créeeee\n");
}

void		set_head(t_asm *e)
{
    int    i[4];
    int    zero;

	ft_memcpy(i, (int[4]){32, 0, 32, 0}, sizeof(int[4]));
    while ((i[0] -= 8) >= 0)
        put_bin(e, &e->head, (int[1]){(char)(COREWAR_EXEC_MAGIC >> i[0])}, 1);
    while (e->champ.valid.name && e->champ.valid.name[i[1]])
        put_bin(e, &e->head, (int[1]){e->champ.valid.name[i[1]++]}, 1);
    if ((zero = PROG_NAME_LENGTH - i[1]))
        put_bin(e, &e->head, (int[PROG_NAME_LENGTH]){}, zero);
    put_bin(e, &e->head, (int[4]){}, 4);
    while ((i[2] -= 8) >= 0)
        put_bin(e, &e->head, (int[1]){(char)(130 >> i[2])}, 1);
    //put_bin(e, &e->head, (int[1]){(char)(e->len_file >> i[2])}, 1);
    while (e->champ.valid.comment && e->champ.valid.comment[i[3]])
        put_bin(e, &e->head, (int[1]){e->champ.valid.comment[i[3]++]}, 1);
    if ((zero = COMMENT_LENGTH - i[3]))
        put_bin(e, &e->head, (int[COMMENT_LENGTH]){}, zero);
    put_bin(e, &e->head, (int[4]){}, 4);
}
