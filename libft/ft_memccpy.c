/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:29:03 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/22 17:29:13 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dst;

	i = 0;
	src = (unsigned char *)s2;
	dst = (unsigned char *)s1;
		while (i < n)
		{
			dst[i] = src[i];
			if (src[i] == c)
				return (&dst[i + 1]);
			i++;
		}
	return ((void *)0);
}
