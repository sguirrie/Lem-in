/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:46:46 by sguirrie          #+#    #+#             */
/*   Updated: 2014/01/26 23:36:41 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void		*new_cont;

	list = (t_list*)malloc(sizeof(t_list));
	if (list)
	{
		list->content_size = 0;
		list->next = NULL;
		if (content)
		{
			if (!(new_cont = (void*)malloc(content_size)))
				list->content = NULL;
			else
			{
				list->content = ft_memcpy(new_cont, content, content_size);
				list->content_size = content_size;
			}
		}
		else
			list->content = NULL;
	}
	return (list);
}
