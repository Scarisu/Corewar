/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ana_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:14:46 by pbernier          #+#    #+#             */
/*   Updated: 2017/12/12 00:47:42 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		arg_reg(t_asm *e, char *line, t_arg *arg)
{
	int		content_len;
	int		ret;
	char	*reg;

	content_len = I + 1;
	if (line[content_len] == '-')
		++content_len;
	while (line[content_len] >= '0' && line[content_len] <= '9')
		++content_len;
	if ((line[content_len] != SEPARATOR_CHAR && line[content_len] != ' ' &&
		line[content_len] != '\n' && line[content_len] != COMMENT_CHAR) ||
		(I + 1) == content_len || line[content_len - 1] == '-')
		return (verbos(e, INVALID_REG));
	if (!(reg = ft_strsub(line, I + 1, content_len - I - 1)))
		error(e, MALLOC);
	arg->arg_value = ft_atoi(reg);
	ft_memdel((void **)&reg);
	arg->type = T_REG;
	if (arg->arg_value < 1 || arg->arg_value > REG_NUMBER)
		return (verbos(e, INVALID_REG));
	if (!(ret = arg_left(e, line, content_len)))
		return (verbos(e, INVALID_REG));
	I = ret;
	return (1);
}

int		arg_val(t_asm *e, char *line, t_arg *arg, int type)
{
	int		content_len;
	int		ret;
	char	*value;

	content_len = (I + 2 - type);
	if (line[content_len] == LABEL_CHAR)
		return (arg_lab(e, line, arg, type));
	if (line[content_len] == '-')
		++content_len;
	while (line[content_len] >= '0' && line[content_len] <= '9')
		++content_len;
	if ((line[content_len] != SEPARATOR_CHAR && line[content_len] != ' ' &&
		line[content_len] != '\n' && line[content_len] != COMMENT_CHAR) ||
		(I + 2 - type) == content_len || line[content_len - 1] == '-')
		return (verbos(e, (type == 1) ? INVALID_DIR_VAL : INVALID_IND_VAL));
	if (!(value = ft_strsub(line, I + 2 - type, content_len - I - (2 - type))))
		error(e, MALLOC);
	arg->arg_value = ft_atoi(value);
	ft_memdel((void **)&value);
	arg->type = (type == 1) ? T_DIR : T_IND;
	if (!(ret = arg_left(e, line, content_len)))
		return (verbos(e, (type == 1) ? INVALID_DIR_VAL : INVALID_IND_VAL));
	I = ret;
	return (1);
}

int		arg_lab(t_asm *e, char *line, t_arg *arg, int type)
{
	int		content_len;
	int		ret;
	char	*label;

	content_len = (I + 4 - (type * 2));
	while (line[content_len] != SEPARATOR_CHAR && line[content_len] != ' '
		&& line[content_len] != '\n' && line[content_len] != COMMENT_CHAR)
		++content_len;
	if (!(label = ft_strsub(line, I + 3 - type, content_len - I - (3 - type))))
		error(e, MALLOC);
	if (!valid_label(label) || !(ret = arg_left(e, line, content_len)))
	{
		ft_memdel((void **)&label);
		return (verbos(e, INVALID_LABEL_ARG));
	}
	arg->arg_label = set_label(e, (int[2]){e->verbos.nb_line, I});
	arg->type = (type == 1) ? T_DIR : T_IND;
	arg->arg_label->octets = e->bin.op_pos;
	!(arg->arg_label->name = ft_strdup(label)) ? error(e, MALLOC) : 0;
	ft_memdel((void **)&label);
	!(arg->arg_label->line = ft_strdup(line)) ? error(e, MALLOC) : 0;
	I = ret;
	return (1);
}

int		arg_left(t_asm *e, char *line, int content_len)
{
	int	ret;

	ret = 0;
	while (line[content_len] == ' ')
		++content_len;
	if (e->enco->nb_arg + 1 < g_op_tab[e->enco->opcode - 1].nb_params)
	{
		if (line[content_len] == COMMENT_CHAR)
			ret = content_len - 1;
		else if (line[content_len] == SEPARATOR_CHAR)
			ret = content_len;
		else
			ret = 0;
	}
	else if (!line[content_len] || line[content_len] == '\n'
		|| line[content_len] == SEPARATOR_CHAR
		|| line[content_len] == COMMENT_CHAR)
		ret = content_len;
	return (ret);
}
