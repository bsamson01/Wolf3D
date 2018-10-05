/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:40:05 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/21 15:03:07 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_chr(char *str, char c)
{
	char	*s1;
	size_t	i;
	size_t	j;

	if (!str || !c)
		return (NULL);
	j = ft_strlen(str);
	s1 = ft_strnew(j + 1);
	if (!s1)
		return (NULL);
	i = -1;
	while (++i < j)
		*(s1 + i) = *(str + i);
	*(s1 + i) = c;
	return (s1);
}
