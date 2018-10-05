/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:38:32 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/18 13:26:05 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	int				result;
	char			*add;

	i = 0;
	sign = 1;
	result = 0;
	add = ft_rem_spaces((char *)str);
	if (add[i] == '-' || add[i] == '+')
	{
		if (add[i] == '-')
			sign = -1;
		i++;
	}
	while (add[i] >= '0' && add[i] <= '9')
	{
		result = result * 10 + add[i] - '0';
		i++;
	}
	return (result * sign);
}
