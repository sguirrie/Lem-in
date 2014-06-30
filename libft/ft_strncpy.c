/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:35:06 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/22 18:21:55 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	const char	*src;
	char		*dest;

	dest = s1;
	src = s2;
	if (!s1 || !s2)
		return ((char *)0);
	while (n > 0 && *src)
	{
		n--;
		*dest = *src;
		src++;
		dest++;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (s1);
}
