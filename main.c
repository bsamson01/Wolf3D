/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <bsamson@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:09:55 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/24 17:34:52 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		print(t_wolf *ren)
{
	int				j;
	static	int		i = 100;

	j = 400;
	if (i < 800)
	{
		mlx_string_put(ren->mlx, ren->win, 350, 330, 0x009944FF,
				"PLease wait while Wolf3D is loading...");
		while (j < 450)
			mlx_pixel_put(ren->mlx, ren->win, i, j++, 0x00994422);
		i++;
	}
	if (i == 800)
		render(ren);
	return (0);
}

int		error_chk_fd(int fd, char *str)
{
	int				i;

	if (fd <= 0)
	{
		ft_putstr("ERROR : Failed to open file : './");
		ft_putstr(str);
		ft_putendl("'. Please check if file path is correct.");
		close(fd);
		return (-1);
	}
	else
	{
		i = ft_strlen(str) - 1;
		if (str[i] != 'f' || str[i - 1] != 'l' || str[i - 2] != 'o'
				|| str[i - 3] != 'w'
				|| str[i - 4] != '.' || i <= 4)
		{
			ft_putstr("ERROR : Invalid map, wolf3D takes maps with");
			ft_putendl(" a '.wolf' extension.");
			close(fd);
			return (-1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_wolf			ren;

	if (ac == 2)
	{
		initialize(&ren);
		if (get_map(av[1], &ren))
			return (-1);
		ren.win = mlx_new_window(ren.mlx,
				(ren.win_x + ren.win_extra + 4), ren.win_y, "Wolf3D");
		ren.map = 1;
		mlx_hook(ren.win, 2, 0, keys, &ren);
		mlx_hook(ren.win, 17, 0, exit_win, &ren);
		mlx_loop_hook(ren.mlx, print, (t_wolf *)&ren);
		mlx_loop(ren.mlx);
	}
	else
		ft_putendl("Invalid number of arguments, Wolf3D takes 1 argument.");
	return (0);
}
