/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 11:26:49 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/04 11:26:51 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	crd_del(t_coord **crd)
{
	t_coord *n;

	if (!(*crd))
		return ;
	while (*crd)
	{
		n = (*crd)->next;
		free(*crd);
		*crd = n;
	}
}

void	map_del(t_mlx **m, int i)
{
	if ((*m)->crd)
		crd_del(&(*m)->crd);
	if ((*m)->ncrd)
		crd_del(&(*m)->ncrd);
	free(*m);
	exit(i);
}
