/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:02:13 by sperkhun          #+#    #+#             */
/*   Updated: 2018/01/26 11:02:15 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_controls(void)
{
	ft_putstr("              CONTROLS:\n\
	turn_______________ keys: 1, 2, 4, 5\n\
	move_______________ keys: up, down, left, right\n\
	zoom_______________ keys: +, -\n\
	change projection__ key:  P\n\
	exit_______________ key:  ESC\n");
}

int		main(int argc, char **argv)
{
	t_mlx	*m;

	if (argc != 2)
	{
		ft_putendl_fd("Error: Wrong number of arguments", 2);
		return (0);
	}
	if (!(m = set_params(argv[1])))
		return (0);
	opnwin(&m);
	draw_image(m);
	put_controls();
	mlx_hook(m->win, 2, 5, &key_hook, m);
	mlx_hook(m->win, 17, 5, exit_x, m);
	mlx_loop(m->mlx);
	return (0);
}
