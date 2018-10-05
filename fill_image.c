/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:58:48 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/20 11:01:47 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fill_in(t_wolf *ren, int x)
{
	int		m;
	int		n;
	int		k;

	m = ren->draw_start * ren->win_x + x;
	n = ren->draw_end * ren->win_x + x;
	k = x;
	while (k < m)
	{
		ren->cur_img_data[k] = 0x00FFFFFF;
		k += ren->win_x;
	}
	while (m <= n)
	{
		ren->cur_img_data[m] = ren->color;
		m += ren->win_x;
	}
	k = (ren->win_y * ren->win_x + x) - ren->win_x;
	while (k > n)
	{
		ren->cur_img_data[k] = 0x00E2893B;
		k -= ren->win_x;
	}
}
