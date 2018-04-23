/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:49:29 by sperkhun          #+#    #+#             */
/*   Updated: 2018/01/24 13:49:32 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define WIN_SIZE_H 1000

# define WIN_SIZE_W 1500

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
	double			c;
	struct s_coord	*next;
	struct s_coord	*prev;
}					t_coord;

typedef struct		s_change
{
	double			d;
	double			tx;
	double			tz;
	double			r;
	double			dw;
	double			p;
}					t_change;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl_img;
	int				bpp;
	int				s_line;
	int				ed;
	t_coord			*crd;
	t_coord			*ncrd;
	t_change		ch;
	int				qts;
	int				qtr;
}					t_mlx;

typedef struct		s_br
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	int				x;
	int				y;
}					t_br;

t_mlx				*set_params(char *str);
t_coord				*read_lines(char *str, t_mlx **mlx);
void				newcrd(t_mlx **mlx);
void				opnwin(t_mlx **mlx);
void				draw_image(t_mlx *mlx);
void				draw(t_mlx *m);
int					key_hook(int key, t_mlx *mlx);
int					exit_x(void *par);
void				crd_del(t_coord **crd);
void				map_del(t_mlx **mlx, int i);
int					get_color(t_coord *c1, t_coord *c2);

#endif
