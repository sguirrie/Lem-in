/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:39:40 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/28 18:49:33 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = malloc(sizeof(unsigned char) * size);
	if (mem && size)
	{
		ft_bzero(mem, size);
		return ((void *)mem);
	}
	return ((void *)0);
}
