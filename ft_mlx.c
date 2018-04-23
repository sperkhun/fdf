/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:13:46 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/03 18:13:47 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	opnwin(t_mlx **m)
{
	(*m)->mlx = mlx_init();
	(*m)->win = mlx_new_window((*m)->mlx, WIN_SIZE_W, WIN_SIZE_H, "FdF");
	if (!(*m)->mlx || !(*m)->win)
	{
		perror("Error");
		map_del(m, 1);
	}
}

void	draw_image(t_mlx *m)
{
	if (!(m->img = mlx_new_image(m->mlx, WIN_SIZE_W, WIN_SIZE_H)))
	{
		perror("Error");
		map_del(&m, 1);
	}
	m->pxl_img = mlx_get_data_addr(m->img, &(m->bpp), \
										&(m->s_line), &(m->ed));
	m->bpp /= 8;
	draw(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	mlx_destroy_image(m->mlx, m->img);
}

int		key_hook(int key, t_mlx *m)
{
	if (key == 53)
	{
		mlx_destroy_window(m->mlx, m->win);
		map_del(&m, 0);
	}
	key == 124 ? m->ch.r += 10 : 0;
	key == 123 ? m->ch.r -= 10 : 0;
	key == 126 ? m->ch.dw -= 10 : 0;
	key == 125 ? m->ch.dw += 10 : 0;
	key == 69 ? m->ch.d -= 5 : 0;
	key == 78 ? m->ch.d += 5 : 0;
	key == 83 || key == 18 ? m->ch.tz += 0.1 : 0;
	key == 86 || key == 21 ? m->ch.tx += 0.1 : 0;
	key == 84 || key == 19 ? m->ch.tz -= 0.1 : 0;
	key == 87 || key == 23 ? m->ch.tx -= 0.1 : 0;
	if (key == 35)
		m->ch.p == 0 ? m->ch.p++ : m->ch.p--;
	newcrd(&m);
	draw_image(m);
	return (0);
}

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}
