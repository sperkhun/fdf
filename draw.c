/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:10:08 by sperkhun          #+#    #+#             */
/*   Updated: 2018/01/30 15:10:09 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawpxl(int x, int y, t_mlx *m, int color)
{
	int i;

	if (x < 0 || x >= WIN_SIZE_W || y < 0 || y >= WIN_SIZE_H)
		return ;
	i = x * m->bpp + y * m->s_line;
	m->pxl_img[i] = color;
	m->pxl_img[++i] = color;
	m->pxl_img[++i] = color;
}

static void	drawif1(t_br b, t_mlx *m)
{
	int i;

	i = 1;
	while (i <= b.dy)
	{
		if (b.d > 0)
		{
			b.d += b.d2;
			b.x += b.sx;
		}
		else
			b.d += b.d1;
		drawpxl(b.x, b.y, m, 0xFFFFFF);
		i++;
		b.y += b.sy;
	}
}

static void	drawif2(t_br b, t_mlx *m)
{
	int i;

	i = 1;
	while (i <= b.dx)
	{
		if (b.d > 0)
		{
			b.d += b.d2;
			b.y += b.sy;
		}
		else
			b.d += b.d1;
		drawpxl(b.x, b.y, m, 0xFFFFFF);
		i++;
		b.x += b.sx;
	}
}

static void	drawline(t_coord *crd1, t_coord *crd2, t_mlx *m)
{
	t_br	b;

	b.dx = fabs(crd2->x - crd1->x);
	b.dy = fabs(crd2->y - crd1->y);
	b.sx = crd2->x >= crd1->x ? 1 : -1;
	b.sy = crd2->y >= crd1->y ? 1 : -1;
	b.d = b.dy > b.dx ? (b.dx << 1) - b.dy : (b.dy << 1) - b.dx;
	b.d1 = b.dy > b.dx ? (b.dx << 1) : (b.dy << 1);
	b.d2 = b.dy > b.dx ? (b.dx - b.dy) << 1 : (b.dy - b.dx) << 1;
	b.x = b.dy > b.dx ? crd1->x : crd1->x + b.sx;
	b.y = b.dy > b.dx ? crd1->y + b.sx : crd1->y;
	drawpxl(crd1->x, crd1->y, m, 0xFFFFFF);
	if (b.dy > b.dx)
		drawif1(b, m);
	else
		drawif2(b, m);
}

void		draw(t_mlx *m)
{
	int		n;
	t_coord	*c;

	c = m->crd;
	n = m->qts - 1;
	while (c)
	{
		if (c->next && n > 0)
			drawline(c, c->next, m);
		if (c->prev)
			drawline(c, c->prev, m);
		c = c->next;
		if (!n)
			n = m->qts - 1;
		else
			n--;
	}
}
