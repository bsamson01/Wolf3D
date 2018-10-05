/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:20:53 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/18 12:21:22 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	if (tmpsrc < tmpdst)
		while (len--)
			tmpdst[len] = tmpsrc[len];
	else
		ft_memcpy(tmpdst, tmpsrc, len);
	return (dst);
}
