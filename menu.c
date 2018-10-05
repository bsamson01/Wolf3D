/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:44:11 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/24 17:44:51 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_menu(t_wolf *ren)
{
	mlx_string_put(ren->mlx, ren->win, 800, 350,
			0x00FAAAAE, "CONTROLS");
	mlx_string_put(ren->mlx, ren->win, 710, 375,
			0x00FF2222, "Left Arrow  :  Turn Left");
	mlx_string_put(ren->mlx, ren->win, 710, 395,
			0x00FF2222, "Right Arrow :  Turn Right");
	mlx_string_put(ren->mlx, ren->win, 710, 415,
			0x00FF2222, "Up Arrow    :  Move Forward");
	mlx_string_put(ren->mlx, ren->win, 710, 435,
			0x00FF2222, "Down Arrow  :  Move Backwards");
	mlx_string_put(ren->mlx, ren->win, 800, 460,
			0x00FAAAAE, "CHEATS");
	mlx_string_put(ren->mlx, ren->win, 710, 485,
			0x00FF2222, "? : Open Secret Doors");
	mlx_string_put(ren->mlx, ren->win, 740, 520,
			0x00FF2222, "ESC    :     Exit game");
}
