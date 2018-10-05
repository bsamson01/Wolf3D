/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 02:44:13 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/26 02:48:17 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_end_of_line(char **save_buff, char **line)
{
	char	*limit;

	if ((limit = ft_strchr(*save_buff, '\n')))
	{
		*line = ft_strsub(*save_buff, 0, limit - *save_buff);
		ft_strcpy(*save_buff, limit + 1);
		return (1);
	}
	return (0);
}

char	*ft_strjoin_2(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = (s1) ? ft_strlen(s1) : 0;
	len2 = ft_strlen(s2);
	result = ft_strnew(len1 + len2);
	if (result)
	{
		if (s1)
			ft_memcpy(result, s1, len1);
		ft_memcpy(result + len1, s2, len2);
	}
	if (s1)
		ft_strdel(&s1);
	return (result);
}

int		get_next_line(const int fd, char **line)
{
	int			bytes_read;
	char		buff[BUFF_SIZE + 1];
	static char	*save_buff = NULL;

	if (save_buff && ft_end_of_line(&save_buff, line))
		return (1);
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		save_buff = ft_strjoin_2(save_buff, buff);
		if (ft_end_of_line(&save_buff, line))
			return (1);
	}
	if (bytes_read < 0)
		return (-1);
	if (save_buff && *save_buff)
	{
		*line = ft_strdup(save_buff);
		ft_strdel(&save_buff);
		return (1);
	}
	if (bytes_read)
		return (1);
	return (0);
}
