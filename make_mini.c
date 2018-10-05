/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:31:04 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/24 18:15:01 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	sort(t_wolf *ren, t_mini *a)
{
	if (a->x == (int)ren->pos_x && a->y == (int)ren->pos_y)
		ren->color = 0x0000FF00;
	else if (ren->int_map[a->y][a->x] != 0 &&
			ren->int_map[a->y][a->x] != 6)
		ren->color = 0x00FF0000;
	else if (ren->int_map[a->y][a->x] == 6)
		ren->color = 0x00999029;
	else
		ren->color = 0x00FFFFFF;
	ren->mini_img_data[((((a->y * a->l) + a->i) * 300) +
			((a->x * a->m) + a->k))] = ren->color;
}

void	make_grid(t_wolf *ren)
{
	t_mini		a;

	a.m = ren->win_extra / ren->max_x;
	a.l = ren->win_extra / ren->max_y;
	ren->mini_img = mlx_new_image(ren->mlx, ren->win_extra, ren->win_extra);
	ren->mini_img_data = (int *)mlx_get_data_addr(ren->mini_img,
			&ren->bp, &ren->si, &ren->end);
	a.y = -1;
	while (++a.y < ren->max_y)
	{
		a.i = -1;
		while (++a.i < a.l)
		{
			a.x = -1;
			while (++a.x < ren->max_x)
			{
				a.k = -1;
				while (++a.k < a.m)
					sort(ren, &a);
			}
		}
	}
	mlx_put_image_to_window(ren->mlx, ren->win,
			ren->mini_img, ren->win_x + 2, 0);
	mlx_destroy_image(ren->mlx, (char *)ren->mini_img);
}
