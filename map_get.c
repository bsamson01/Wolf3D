/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <bsamson@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:10:36 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/24 18:00:12 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_scale(t_wolf *ren)
{
	ren->scale_x = 1;
	ren->scale_y = 1;
	ren->win_x = 700;
	ren->win_y = 700;
	ren->win_extra = 300;
}

void	get_int_map(t_wolf *ren, char *map)
{
	int		fd;
	int		x;
	int		y;
	char	*line;
	int		i;

	fd = open(map, O_RDONLY);
	y = 0;
	ren->int_map = (int **)malloc(sizeof(int *) * ren->max_y);
	while (get_next_line(fd, &line) > 0)
	{
		ren->int_map[y] = (int *)malloc(ren->max_x * sizeof(int));
		i = 0;
		x = 0;
		while (line[i])
		{
			if (ft_isdigit(line[i]))
				ren->int_map[y][x++] = line[i] - '0';
			i++;
		}
		free(line);
		y++;
	}
	close(fd);
}

int		len(char *line)
{
	ft_putendl("ERROR : Map length irregular.");
	ft_strdel(&line);
	return (-1);
}

int		get_map(char *map, t_wolf *ren)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(map, O_RDONLY);
	if (error_chk_fd(fd, map))
		return (-1);
	ren->max_y = 0;
	ren->max_x = 0;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ren->max_y == 0)
			ren->max_x = ft_cntwrd(line, ' ');
		else if (ft_cntwrd(line, ' ') != ren->max_x)
			return (len(line));
		ren->max_y++;
		ft_strdel(&line);
	}
	close(fd);
	get_scale(ren);
	get_int_map(ren, map);
	return (0);
}
