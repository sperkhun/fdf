/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:25:42 by sperkhun          #+#    #+#             */
/*   Updated: 2018/01/29 13:25:43 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_crdend(t_coord **alst, t_coord *new)
{
	t_coord *bgn;

	if (!alst || !new)
		return ;
	bgn = *alst;
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = new;
	*alst = bgn;
}

static int		coord(t_coord **crd, t_coord **prev, char **str, int i[4])
{
	int		j;
	t_coord	*new;

	j = 0;
	while (str[j])
	{
		if (!(new = (t_coord*)malloc(sizeof(t_coord))))
		{
			crd_del(crd);
			return (0);
		}
		new->x = j - i[2] / 2;
		new->y = i[0] - i[3] / 2;
		new->z = ft_atoi(str[j]);
		new->c = new->z;
		new->next = NULL;
		new->prev = i[0] == 0 ? NULL : *prev;
		new->prev ? *prev = (*prev)->next : 0;
		!*crd ? *crd = new : ft_crdend(crd, new);
		j++;
	}
	return (1);
}

t_coord			*read_lines(char *str, t_mlx **m)
{
	char	**mas;
	char	*line;
	int		i[5];
	t_coord *crd;
	t_coord *prev;

	i[0] = 0;
	i[1] = open(str, O_RDONLY);
	i[2] = (*m)->qts;
	i[3] = (*m)->qtr;
	crd = NULL;
	while ((i[4] = get_next_line(i[1], &line)) > 0)
	{
		(*m)->qts = ft_cntwrd(line, ' ');
		!(mas = ft_strsplit(line, ' ')) ? map_del(m, 1) : 0;
		!coord(&crd, &prev, mas, i) ? map_del(m, 1) : 0;
		i[0] == 0 ? prev = crd : 0;
		ft_strdel(&line);
		ft_arrdel(mas, i[2]);
		i[0]++;
	}
	i[4] < 0 ? map_del(m, 1) : 0;
	close(i[1]);
	return (crd);
}
