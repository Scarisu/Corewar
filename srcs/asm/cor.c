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
	while (i < e->bin.len_head)
		ft_putchar_fd(e->bin.head[i++], fd);
	i = 0;
    //printf("{%zu}\n", e->bin.len_file);
	while (i < e->bin.len_file)
		ft_putchar_fd(e->bin.file[i++], fd);
	ft_putstr(e->champ.file_name);
	ft_putstr(".cor a bien été créeeee\n");
}

void		set_head(t_asm *e)
{
    int    i[4];
    int    zero;

	ft_memcpy(i, (int[4]){32, 0, 32, 0}, sizeof(int[4]));
    while ((i[0] -= 8) >= 0)
        put_bin(e, &e->bin.head, (int[1]){(char)(COREWAR_EXEC_MAGIC >> i[0])}, 1);
    while (e->champ.valid.name && e->champ.valid.name[i[1]])
        put_bin(e, &e->bin.head, (int[1]){e->champ.valid.name[i[1]++]}, 1);
    if ((zero = PROG_NAME_LENGTH - i[1]))
        put_bin(e, &e->bin.head, (int[PROG_NAME_LENGTH]){}, zero);
    put_bin(e, &e->bin.head, (int[4]){}, 4);
    while ((i[2] -= 8) >= 0)
        put_bin(e, &e->bin.head, (int[1]){(char)(e->bin.len_file >> i[2])}, 1);
    while (e->champ.valid.comment && e->champ.valid.comment[i[3]])
        put_bin(e, &e->bin.head, (int[1]){e->champ.valid.comment[i[3]++]}, 1);
    if ((zero = COMMENT_LENGTH - i[3]))
        put_bin(e, &e->bin.head, (int[COMMENT_LENGTH]){}, zero);
    put_bin(e, &e->bin.head, (int[4]){}, 4);
}

void	set_file(t_asm *e, t_enco *i)
{
    int shift;
	int	nb;

	i = e->enco_start;
	while (i && i->next)
	{
		put_bin(e, &e->bin.file, (int[1]){i->opcode}, 1);
		if (i->opcode != LIVE && i->opcode != ZJMP &&
            i->opcode != FORK && i->opcode != LFORK)
			put_bin(e, &e->bin.file, (int[1]){i->bin_arg}, 1);
		nb = -1;
		while (++nb < i->nb_arg)
		{
            shift = (i->arg[nb].type == T_REG) ? 1 : 2;
            shift += (i->arg[nb].type == T_DIR &&
            (i->opcode == LIVE || i->opcode == LD || i->opcode == AND ||
            i->opcode == OR || i->opcode == XOR || i->opcode == LLD)) ? 2 : 0;
            shift *= 8;
            if (i->arg[nb].arg_label)
			 	exist_label(e, i->arg[nb].arg_label, &e->champ.valid, shift);
            else
                while ((shift -= 8) >= 0)
                    put_bin(e, &e->bin.file,
                    (int[1]){i->arg[nb].arg_value >> shift}, 1);
        }
		i = i->next;
	}
}
