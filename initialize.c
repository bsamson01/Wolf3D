/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <bsamson@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:10:19 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/24 18:38:42 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	initialize_2(t_wolf *ren)
{
	ren->map = 0;
	ren->bpp = 0;
	ren->endian = 0;
	ren->map_x = 0;
	ren->map_y = 0;
	ren->step_x = 0;
	ren->step_y = 0;
	ren->hit = 0;
	ren->side = 0;
	ren->line_height = 0;
	ren->draw_start = 0;
	ren->draw_end = 0;
	ren->color = 0;
	ren->side_dist_x = 0;
	ren->side_dist_y = 0;
	ren->delta_dist_x = 0;
	ren->delta_dist_y = 0;
	ren->perp_wall_dist = 0;
}

void	initialize(t_wolf *ren)
{
	ren->pos_x = 1.5;
	ren->pos_y = 1.5;
	ren->dir_x = 1;
	ren->dir_y = 0;
	ren->cur_img = NULL;
	ren->prev_img = NULL;
	ren->mlx = mlx_init();
	ren->plane_x = 0;
	ren->plane_y = 0.66;
	ren->camera_x = 0;
	ren->win_x = 0;
	ren->win_y = 0;
	ren->scale_x = 0;
	ren->scale_y = 0;
	ren->max_x = 0;
	ren->max_y = 0;
	ren->camera_x = 0;
	ren->ray_dir_x = 1;
	ren->ray_dir_y = 0;
	ren->cur_img_data = NULL;
	ren->size_l = 0;
	initialize_2(ren);
}
