/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:24:35 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/27 14:20:14 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = (unsigned int)n;
	if (!n)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && --i > 0)
	{
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	if (*s1 < *s2)
		return (-1);
	return (0);
}
