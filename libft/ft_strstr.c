/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:45:12 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/18 12:45:26 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(s2);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j])
			{
				j++;
				if (j == len)
					return ((char *)s1 + i);
			}
		}
		i++;
	}
	return (0);
}
