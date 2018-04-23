/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcrd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:36:08 by sperkhun          #+#    #+#             */
/*   Updated: 2018/01/25 11:36:10 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	turn_x(t_coord **crd, t_coord *ncrd, double rad)
{
	double y;
	double z;

	if (!rad)
		return ;
	y = (*crd)->y;
	z = ncrd->z;
	(*crd)->y = y * cos(rad) + -z * sin(rad);
	(*crd)->z = -y * sin(rad) + -z * cos(rad);
}

static void	turn_z(t_coord **crd, t_coord *ncrd, double rad)
{
	double x;
	double y;

	if (!rad)
		return ;
	x = ncrd->x;
	y = ncrd->y;
	(*crd)->x = x * cos(rad) - y * sin(rad);
	(*crd)->y = x * sin(rad) + y * cos(rad);
}

void		newcrd(t_mlx **m)
{
	t_coord	*new;
	t_coord	*st;
	int		h;

	h = WIN_SIZE_H;
	new = (*m)->crd;
	st = (*m)->ncrd;
	while (new)
	{
		turn_z(&new, st, (*m)->ch.tz);
		turn_x(&new, st, (*m)->ch.tx);
		if ((*m)->ch.p)
		{
			new->x = (new->x) * (h / ((*m)->ch.d + new->z)) + (*m)->ch.r;
			new->y = (new->y) * (h / ((*m)->ch.d + new->z)) + (*m)->ch.dw;
		}
		else
		{
			new->x = (new->x) * (h / (*m)->ch.d) + (*m)->ch.r;
			new->y = (new->y) * (h / (*m)->ch.d) - new->z + (*m)->ch.dw;
		}
		new = new->next;
		st = st->next;
	}
}
