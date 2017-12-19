/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 05:00:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/14 06:25:58 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

char		*get_file(char *path, int *len)
{
	int		i;
	int		fd;
	char	tmp;
	char	*result;

	i = 0;
	if (!(fd = open(path, O_RDONLY)))
		exit(-1);
	result = ft_strnew(0);
	while ((read(fd, &tmp, 1)))
	{
		result = realloc(result, ++i + 1);
		result[i] = tmp;
	}
	close(fd);
	*len = i;
	return (result);
}

int		main(int argc, char **argv)
{
	int		i;
	int		len1;
	int		len2;
	char	*str1;
	char	*str2;

	if (argc == 3)
	{
		str1 = get_file(argv[1], &len1);
		str2 = get_file(argv[2], &len2);
		ft_putendl("[REAL] - [MINE]");
		ft_putchar('[');
		ft_putnbr(len1);
		ft_putstr("] - [");
		ft_putnbr(len2);
		ft_putendl("]\n");
		//i = 2190;
		i = -1;
		while (i <= len1 || i <= len2)
		{
			if (i >= 2193)
			{
				ft_putchar('{');
				if (i - 2192 < 10)
					ft_putchar('0');
				if (i - 2192 < 100)
					ft_putchar('0');
				ft_putnbr(i - 2192);
				ft_putstr("} .");
			}
			else
				ft_putstr("       ");

			ft_putchar('[');
			if (i <= len1)
				ft_putnbr(str1[i]);
			else
				ft_putchar('/');
			ft_putchar(']');
			if (str1[i] < 10 && str1[i] >= 0)
				ft_putstr("   ");
			else if ((str1[i] < 100 && str1[i] >= 10) || (str1[i] < 0 && str1[i] > -10))
				ft_putstr("  ");
			else if ((str1[i] >= 100) || (str1[i] <= 10 && str1[i] > -100))
				ft_putchar(' ');

			ft_putstr(" - [");
			if (i <= len2)
				ft_putnbr(str2[i]);
			else
				ft_putchar('/');
			ft_putchar(']');
			if (str2[i] < 10 && str2[i] >= 0)
				ft_putstr("   ");
			else if ((str2[i] < 100 && str2[i] >= 10) || (str2[i] < 0 && str2[i] > -10))
				ft_putstr("  ");
			else if ((str2[i] >= 100) || (str2[i] <= 10 && str2[i] > -100))
				ft_putchar(' ');

			if ((i <= len1 && i <= len2 && str1[i] != str2[i]) ||
				i > len1 || i > len2)
				ft_putstr("  {DIFF}");
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
