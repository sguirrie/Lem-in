/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:29:54 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/22 17:29:56 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (dest <= src || src >= (dest + n))
	{
		while (n--)
			*dest++ = *src++;
	}
	else
	{
		dest = dest + n - 1;
		src = src + n - 1;
		while (n--)
			*dest-- = *src--;
	}
	return (s1);
}
