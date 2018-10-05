/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:10:29 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/20 09:10:31 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_color(t_wolf *ren)
{
	if (ren->int_map[ren->map_y][ren->map_x] == 1)
		ren->color = 0x00B1C2C3;
	else if (ren->int_map[ren->map_y][ren->map_x] == 2)
		ren->color = 0x003C2854;
	else if (ren->int_map[ren->map_y][ren->map_x] == 3)
		ren->color = 0x0000FF00;
	else if (ren->int_map[ren->map_y][ren->map_x] == 4)
		ren->color = 0x070800FF;
	else if (ren->int_map[ren->map_y][ren->map_x] == 5)
		ren->color = 0x00FF00FF;
	else
		ren->color = 0x00FFFF00;
	if (ren->side == 1 && ren->int_map[ren->map_y][ren->map_x] != 1)
		ren->color /= 2;
}
