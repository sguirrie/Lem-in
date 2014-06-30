/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:00:31 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/29 17:02:11 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((!s1 && !s2) || n == 0)
		return (1);
	if (s1 && s2)
	{
		while (n > 0 && *s1 && *s2)
		{
			if (*s1++ == *s2++)
				n--;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
