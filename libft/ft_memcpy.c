/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:29:33 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/22 17:29:35 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	const char		*src;
	char			*dst;

	i = 0;
	src = s2;
	dst = s1;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (s1);
}
