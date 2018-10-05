/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <bsamson@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:10:50 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/24 18:34:39 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include "libft/libft.h"
# include <math.h>

# define MAP1 "./maps/level1.wolf"
# define MAP2 "./maps/level2.wolf"

typedef	struct	s_mini
{
	int			x;
	int			y;
	int			i;
	int			l;
	int			k;
	int			m;
}				t_mini;

typedef	struct	s_wolf
{
	void		*mlx;
	void		*win;
	int			**int_map;
	int			win_x;
	int			win_y;
	int			scale_x;
	int			scale_y;
	int			max_y;
	int			max_x;
	int			win_extra;
	double		plane_x;
	double		plane_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	void		*cur_img;
	int			*cur_img_data;
	void		*mini_img;
	int			*mini_img_data;
	void		*prev_img;
	int			size_l;
	int			bpp;
	int			endian;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			si;
	int			end;
	int			bp;
	int			map;
}				t_wolf;

void			get_color(t_wolf *ren);
void			fill_in(t_wolf *ren, int x);
void			get_cood(t_wolf *ren);
void			check_hit(t_wolf *ren);
void			get_step(t_wolf *ren);
void			ren_img(t_wolf *ren);
void			wolf(t_wolf *ren);
void			initialize(t_wolf *ren);
void			render(t_wolf *ren);
int				exit_win(t_wolf *ren);
int				error_chk_fd(int fd, char *str);
int				keys(int key, t_wolf *ren);
int				get_map(char *map, t_wolf *ren);
void			make_grid(t_wolf *ren);
void			put_menu(t_wolf *ren);
void			end_game(t_wolf *ren);
void			next_level(t_wolf *ren);

#endif
