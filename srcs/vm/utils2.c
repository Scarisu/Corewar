/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 04:14:13 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/03 12:08:02 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

bool	false_cmd(t_corewar *d, t_reg *reg, bool carry)
{
	(void)d;
	jump_to_next(reg, 1);
	if (carry)
		reg->carry = 0;
	return (true);
}

bool	valid_ocp(t_ocp *ocp, unsigned char op)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = 0;
	while (++i < 3)
	{
		if (ocp->p[i] == O_NONE)
			tmp++;
		if ((g_op_tab[op].type[i] & ocp->p[i]) != ocp->p[i])
			return (false);
	}
	if (tmp != 3 - g_op_tab[op].nb_params)
		return (false);
	return (true);
}

void	true_pc(int *pc)
{
	while (*pc >= MEM_SIZE || *pc < 0)
	{
		if (*pc >= MEM_SIZE)
			*pc -= MEM_SIZE;
		else
			*pc += MEM_SIZE;
	}
}

void	put_hexa(t_corewar *d, int nbc, int pc, int value)
{
	int		i;
	int		len;

	i = -1;
	len = 4;
	true_pc(&pc);
	while (++i < len)
	{
		d->map[pc] = value >> 8 * (len - i - 1);
		d->colors[pc] = nbc;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
	}
}

int		get_modulo(int n, int modulo)
{
	if (n < 0)
		n = n % -modulo;
	else
		n = n % modulo;
	return (n);
}
