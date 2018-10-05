/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:28:28 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/24 17:54:02 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	end_game(t_wolf *ren)
{
	mlx_clear_window(ren->mlx, ren->win);
	mlx_string_put(ren->mlx, ren->win, 390, 350, 0x00FF00FF, "CONGRATULATIONS");
	mlx_string_put(ren->mlx, ren->win, 310, 380, 0x00FF00AA,
			"You have completed the free trial.");
	mlx_string_put(ren->mlx, ren->win, 310, 410, 0x00FF00AA,
			"The full game will be available soon.");
	mlx_string_put(ren->mlx, ren->win, 320, 600, 0x00FF0000,
			"Press ESC or the red cross to exit");
}

void	next_level(t_wolf *ren)
{
	int		y;

	y = 0;
	while (y < ren->max_y)
		free(ren->int_map[y++]);
	free(ren->int_map);
	ren->pos_x = 14.5;
	ren->pos_y = 1.5;
	get_map(MAP2, ren);
	ren->map = 2;
	render(ren);
}
