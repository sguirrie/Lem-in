/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:30:15 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/27 14:40:47 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*cpy;

	if (s)
	{
		cpy = (const unsigned char *)s;
		while (--n && cpy)
		{
			if (*cpy == c)
				return ((void *)cpy);
			cpy++;
		}
	}
	return (NULL);
}
