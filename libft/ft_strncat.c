/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:10:45 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/27 13:42:10 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*cpy;

	cpy = s1;
	while (*cpy)
		cpy++;
	while (*s2 && n--)
	{
		*cpy = *s2;
		cpy++;
		s2++;
	}
	*cpy = '\0';
	return (s1);
}
