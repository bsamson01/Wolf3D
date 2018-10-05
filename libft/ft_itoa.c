/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:12:48 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/18 12:13:11 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *out;

	if (!(out = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(out, "-2147483648"));
	if (n < 0)
	{
		out[0] = '-';
		out[1] = '\0';
		out = ft_strjoin(out, ft_itoa(-n));
	}
	else if (n >= 10)
		out = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		out[0] = n + '0';
		out[1] = '\0';
	}
	return (out);
}
