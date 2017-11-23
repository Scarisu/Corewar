/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:38:43 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:16:39 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_gnl		*ft_newlst(t_gnl *gnl, int size, const int fd, int wf)
{
	if (wf == 1)
	{
		if (!(gnl = (struct s_gnl*)malloc(sizeof(struct s_gnl) * size)))
			return (NULL);
		gnl->adr = NULL;
		gnl->head = NULL;
		gnl->keep = NULL;
		gnl->ret = 0;
		gnl->gol = 0;
		gnl->fd = fd;
		gnl->before = NULL;
		gnl->next = NULL;
		return (gnl);
	}
	else if (wf == 2)
	{
		if (!(gnl->next = ft_newlst(gnl, 1, fd, 1)))
			return (NULL);
		gnl->next->before = gnl;
		return (gnl);
	}
	return (NULL);
}

static int			ft_verif(const int fd, t_gnl **gnl, t_gsml *g, char **l)
{
	if (fd < 0 || BUFF_SIZE <= 0 || l == NULL)
		return (-1);
	if (!(*gnl))
		if (!((*gnl) = ft_newlst((*gnl), 1, fd, 1)))
			return (-1);
	if ((*gnl)->fd != fd)
	{
		while ((*gnl)->before)
			*gnl = (*gnl)->before;
		while ((*gnl)->fd != fd)
		{
			if ((*gnl)->next)
				*gnl = (*gnl)->next;
			else if (!(*gnl = ft_newlst(*gnl, 1, fd, 2)))
				return (-1);
		}
	}
	if (!((*gnl)->keep))
	{
		(*gnl)->keep = ft_strnew(0);
		(*gnl)->head = (*gnl)->keep;
	}
	g->tmp = ft_strnew(BUFF_SIZE);
	return (1);
}

static int			ft_gsl(int fd, char **l, t_gnl **g, t_gsml *gsml)
{
	if (((*g)->ret = read(fd, gsml->tmp, BUFF_SIZE)) == -1)
		return (-1);
	else if ((*g)->ret == 0 && ft_strlen((*g)->keep) == 0)
		(*g)->keep[ft_strlen((*g)->keep)] = '\n';
	else if (*((*g)->keep) == '\n')
	{
		*l = ft_strnew(0);
		gsml->keep_tmp = ft_strjoin((*g)->keep + 1, gsml->tmp);
		ft_strdel(&(*g)->head);
		(*g)->keep = ft_strdup(gsml->keep_tmp);
		(*g)->head = (*g)->keep;
		ft_strdel(&(gsml->tmp));
		ft_strdel(&(gsml->keep_tmp));
		return (1);
	}
	else
		(gsml->tmp)[(*g)->ret] = '\0';
	gsml->keep_tmp = ft_strjoin((*g)->keep, gsml->tmp);
	(*g)->keep = ft_strdup(gsml->keep_tmp);
	ft_strdel(&(*g)->head);
	(*g)->head = (*g)->keep;
	if (!((*g)->adr = ft_strchr((*g)->keep, '\n')) && (*g)->ret == 0)
		(*g)->keep[ft_strlen((*g)->keep)] = '\n';
	return (0);
}

static int			ft_gml(t_gnl **g, char **t, char **kt, t_gnl **s_tmp)
{
	if (((*g)->ret > 0 || ft_strlen((*g)->keep) > 0) && *((*g)->keep) != '\n')
	{
		(*g)->keep = ft_strdup((*g)->adr + 1);
		ft_strdel(&(*g)->head);
		(*g)->head = (*g)->keep;
	}
	else
	{
		*s_tmp = (*g);
		if ((*g)->before)
		{
			(*g) = (*g)->before;
			(*g)->next = (*s_tmp)->next;
		}
		else if ((*g)->next)
		{
			(*g) = (*g)->next;
			(*g)->before = (*s_tmp)->before;
		}
		ft_strdel(&(*kt));
		ft_strdel(&(*t));
		ft_strdel(&(*g)->head);
		return (0);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	t_gsml				gsml;
	static t_gnl		*gnl;
	t_gnl				*s_tmp;

	if ((ft_verif(fd, &gnl, &gsml, line)) == -1)
		return (-1);
	if ((gnl->gol = ft_gsl(fd, line, &gnl, &gsml)) == -1)
		return (-1);
	else if (gnl->gol == 1)
		return (1);
	if (!(gnl->adr = ft_strchr(gnl->keep, '\n')) && gnl->ret != 0)
	{
		get_next_line(fd, line);
		ft_strdel(&(gsml.keep_tmp));
		return (1);
	}
	*(gnl->adr) = '\0';
	*line = ft_strdup(gnl->keep);
	if ((gnl->gol = ft_gml(&gnl, &(gsml.tmp), &(gsml.keep_tmp), &s_tmp)) == 0)
		return (0);
	ft_strdel(&(gsml.tmp));
	ft_strdel(&(gsml.keep_tmp));
	return (1);
}
