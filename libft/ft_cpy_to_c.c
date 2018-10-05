/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_to_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:26:28 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/23 18:06:58 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cpy_to_c(char **dest, char *src, char c, int nbr)
{
	int		i;
	int		cnt;
	int		j;

	ft_putendl(src);
	i = nbr - 1;
	cnt = nbr;
	while (src[++i])
		if (src[i] == c)
			break ;
	j = i;
	i = 0;
	ft_putendl(src);
	if (!(*dest = ft_strnew(j)))
		return (0);
	while (src[cnt] && cnt < j)
	{
		if (!(*dest = ft_str_chr(*dest, src[cnt])))
			return (0);
		cnt++;
	}
	return (i);
}
