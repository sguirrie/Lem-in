/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:08:40 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/27 14:52:07 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*cpy;

	cpy = s1;
	while (*cpy)
		cpy++;
	while (*s2)
	{
		*cpy = *s2;
		cpy++;
		s2++;
	}
	*cpy = '\0';
	return (s1);
}
