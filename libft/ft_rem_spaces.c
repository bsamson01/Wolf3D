/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:06:33 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/18 12:07:19 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rem_spaces(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = (char *)malloc(ft_strlen(str) * sizeof(char));
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	while (str[i])
	{
		result[j] = str[i];
		i++;
		j++;
	}
	return (result);
}
