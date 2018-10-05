/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:57:42 by bsamson           #+#    #+#             */
/*   Updated: 2018/06/20 15:06:36 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*link;

	if (!(link = (t_list *)malloc(sizeof(*link))))
		return (NULL);
	if (!content)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		if (!(link->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}
