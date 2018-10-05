/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <bsamson@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:10:10 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/24 18:40:12 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	mv_side(int key, t_wolf *ren)
{
	if (key == 126)
	{
		if (ren->int_map[(int)(ren->pos_y)]
				[(int)(ren->pos_x + ren->dir_x)] == 0)
			ren->pos_x += ren->dir_x;
		if (ren->int_map[(int)(ren->pos_y + ren->dir_y)]
				[(int)(ren->pos_x)] == 0)
			ren->pos_y += ren->dir_y;
	}
	else if (key == 125)
	{
		if (ren->int_map[(int)(ren->pos_y)]
				[(int)(ren->pos_x - ren->dir_x)] == 0)
			ren->pos_x -= ren->dir_x;
		if (ren->int_map[(int)(ren->pos_y - ren->dir_y)]
				[(int)(ren->pos_x)] == 0)
			ren->pos_y -= ren->dir_y;
	}
}

void	lk_side(int key, t_wolf *ren)
{
	double		old_dir_x;
	double		old_plane_x;

	if (key == 123)
	{
		old_dir_x = ren->dir_x;
		ren->dir_x = ren->dir_x * cos(-0.1) - ren->dir_y * sin(-0.1);
		ren->dir_y = old_dir_x * sin(-0.1) + ren->dir_y * cos(-0.1);
		old_plane_x = ren->plane_x;
		ren->plane_x = ren->plane_x * cos(-0.1) - ren->plane_y * sin(-0.1);
		ren->plane_y = old_plane_x * sin(-0.1) + ren->plane_y * cos(-0.1);
	}
	else if (key == 124)
	{
		old_dir_x = ren->dir_x;
		ren->dir_x = ren->dir_x * cos(0.1) - ren->dir_y * sin(0.1);
		ren->dir_y = old_dir_x * sin(0.1) + ren->dir_y * cos(0.1);
		old_plane_x = ren->plane_x;
		ren->plane_x = ren->plane_x * cos(0.1) - ren->plane_y * sin(0.1);
		ren->plane_y = old_plane_x * sin(0.1) + ren->plane_y * cos(0.1);
	}
}

int		exit_win(t_wolf *ren)
{
	int			y;

	mlx_destroy_window(ren->mlx, ren->win);
	y = 0;
	while (y < ren->max_y)
	{
		free(ren->int_map[y]);
		y++;
	}
	free(ren->int_map);
	exit(0);
}

void	open_secret_path(t_wolf *ren)
{
	if (ren->int_map[2][3] == 2)
		ren->int_map[2][3] = 0;
	else if (ren->int_map[2][3] == 0)
		ren->int_map[2][3] = 2;
	if (ren->int_map[9][2] == 3)
		ren->int_map[9][2] = 0;
	else if (ren->int_map[9][2] == 0)
		ren->int_map[9][2] = 3;
}

int		keys(int key, t_wolf *ren)
{
	if (key == 53)
		exit_win(ren);
	else if (key == 125 || key == 126)
		mv_side(key, ren);
	else if (key == 123 || key == 124)
		lk_side(key, ren);
	else if (key == 44)
		open_secret_path(ren);
	mlx_clear_window(ren->mlx, ren->win);
	render(ren);
	return (0);
}
