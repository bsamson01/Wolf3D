/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:07:58 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/20 11:24:43 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"

void	get_d(t_line *a, t_point *points)
{
	a->dx = abs(points->end_x - points->start_x);
	a->dy = abs(points->end_y - points->start_y);
	a->sx = points->start_x < points->end_x ? 1 : -1;
	a->sy = points->start_y < points->end_y ? 1 : -1;
	a->err = (a->dx > a->dy ? a->dx : -a->dy) / 2;
	a->j = 5;
}

void	line(t_point *points)
{
	t_line		a;

	get_d(&a, points);
	while (a.j)
	{
		mlx_pixel_put(points->mlx, points->win,
				points->start_x, points->start_y, points->color);
		if (points->start_x == points->end_x &&
				points->start_y == points->end_y)
			break ;
		a.e2 = a.err;
		if (a.e2 > -a.dx)
		{
			a.err -= a.dy;
			points->start_x += a.sx;
		}
		if (a.e2 < a.dy)
		{
			a.err += a.dx;
			points->start_y += a.sy;
		}
	}
}
