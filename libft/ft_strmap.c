/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:37:26 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/18 12:37:45 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
