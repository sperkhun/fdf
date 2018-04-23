/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:46:49 by sperkhun          #+#    #+#             */
/*   Updated: 2018/01/29 17:46:50 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setmod(t_mlx **m)
{
	(*m)->ch.d = 40;
	(*m)->ch.tx = 1.1;
	(*m)->ch.tz = 0.8;
	(*m)->ch.r = WIN_SIZE_W / 2;
	(*m)->ch.dw = WIN_SIZE_H / 2;
	(*m)->ch.p = 0;
}

static void	map_size(char *str, t_mlx **m)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(str, O_RDONLY);
	(*m)->qtr = 0;
	while ((n = get_next_line(fd, &line)) > 0)
	{
		if ((*m)->qtr == 0)
			(*m)->qts = ft_cntwrd(line, ' ');
		if ((*m)->qts != ft_cntwrd(line, ' '))
		{
			ft_putendl_fd("Error: Invalid file", 2);
			map_del(m, 1);
		}
		ft_strdel(&line);
		(*m)->qtr++;
	}
	if ((n == 0 && (*m)->qtr == 0) || n < 0)
	{
		n == 0 ? ft_putendl_fd("Error: File is empty", 2) : perror("Error");
		map_del(m, 1);
	}
	close(fd);
}

t_mlx		*set_params(char *str)
{
	t_mlx	*m;

	if (!(m = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	m->crd = NULL;
	m->ncrd = NULL;
	map_size(str, &m);
	m->crd = read_lines(str, &m);
	m->ncrd = read_lines(str, &m);
	setmod(&m);
	newcrd(&m);
	return (m);
}
