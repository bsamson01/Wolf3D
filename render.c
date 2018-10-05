/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <bsamson@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:10:02 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/24 17:53:13 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_step(t_wolf *ren)
{
	if (ren->ray_dir_x < 0)
	{
		ren->step_x = -1;
		ren->side_dist_x = (ren->pos_x - ren->map_x) * ren->delta_dist_x;
	}
	else
	{
		ren->step_x = 1;
		ren->side_dist_x = (ren->map_x + 1.0 - ren->pos_x) * ren->delta_dist_x;
	}
	if (ren->ray_dir_y < 0)
	{
		ren->step_y = -1;
		ren->side_dist_y = (ren->pos_y - ren->map_y) * ren->delta_dist_y;
	}
	else
	{
		ren->step_y = 1;
		ren->side_dist_y = (ren->map_y + 1.0 - ren->pos_y) * ren->delta_dist_y;
	}
}

void	check_hit(t_wolf *ren)
{
	while (ren->hit == 0)
	{
		if (ren->side_dist_x < ren->side_dist_y)
		{
			ren->side_dist_x += ren->delta_dist_x;
			ren->map_x += ren->step_x;
			ren->side = 0;
		}
		else
		{
			ren->side_dist_y += ren->delta_dist_y;
			ren->map_y += ren->step_y;
			ren->side = 1;
		}
		if (ren->int_map[ren->map_y][ren->map_x] > 0)
			ren->hit = 1;
	}
}

void	get_cood(t_wolf *ren)
{
	if (ren->side == 0)
		ren->perp_wall_dist = (ren->map_x - ren->pos_x +
				(1 - ren->step_x) / 2) / ren->ray_dir_x;
	else
		ren->perp_wall_dist = (ren->map_y - ren->pos_y +
				(1 - ren->step_y) / 2) / ren->ray_dir_y;
	ren->line_height = (int)(ren->win_y / ren->perp_wall_dist);
	ren->draw_start = -ren->line_height / 2 + ren->win_y / 2;
	if (ren->draw_start < 0)
		ren->draw_start = 0;
	ren->draw_end = ren->line_height / 2 + ren->win_y / 2;
	if (ren->draw_end >= ren->win_y)
		ren->draw_end = ren->win_y - 1;
}

void	ren_img(t_wolf *ren)
{
	int	x;

	x = -1;
	while (x++ < ren->win_x)
	{
		ren->camera_x = (2 * x / (double)ren->win_x - 1);
		ren->ray_dir_x = ren->dir_x + ren->plane_x * ren->camera_x;
		ren->ray_dir_y = ren->dir_y + ren->plane_y * ren->camera_x;
		ren->map_x = ren->pos_x;
		ren->map_y = ren->pos_y;
		ren->delta_dist_x = fabs(1 / ren->ray_dir_x);
		ren->delta_dist_y = fabs(1 / ren->ray_dir_y);
		ren->hit = 0;
		get_step(ren);
		check_hit(ren);
		get_cood(ren);
		get_color(ren);
		fill_in(ren, x);
	}
}

void	render(t_wolf *ren)
{
	if (ren->map == 2 && (int)ren->pos_x == 1 && (int)ren->pos_y == 12)
		end_game(ren);
	else
	{
		if ((int)ren->pos_x == 1 && (int)ren->pos_y == 10 && ren->map == 1)
			next_level(ren);
		else
		{
			ren->cur_img = mlx_new_image(ren->mlx, ren->win_x, ren->win_y);
			ren->cur_img_data = (int *)mlx_get_data_addr(ren->cur_img,
				&ren->bpp, &ren->size_l, &ren->endian);
			ren_img(ren);
			mlx_clear_window(ren->mlx, ren->win);
			make_grid(ren);
			put_menu(ren);
			mlx_put_image_to_window(ren->mlx, ren->win, ren->cur_img, 0, 0);
			mlx_destroy_image(ren->mlx, (char *)ren->cur_img);
		}
	}
}
