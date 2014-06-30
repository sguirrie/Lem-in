/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:30:42 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/22 17:30:46 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cpy1;
	const unsigned char	*cpy2;

	if (s1 && s2)
	{
		cpy1 = (const unsigned char *)s1;
		cpy2 = (const unsigned char *)s2;
		while (*cpy1 && *cpy2 && *cpy1 == *cpy2 && n--)
		{
			cpy1++;
			cpy2++;
		}
		if (n)
			return (*cpy1 - *cpy2);
		else
			return (0);
	}
	return (0);
}
