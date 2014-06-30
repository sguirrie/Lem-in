/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 19:07:13 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/29 13:42:00 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	if (size > 0)
	{
		i = (unsigned int)size + 1;
		str = (char *)malloc(sizeof(char) * i);
		if (str)
		{
			while (--i > 0)
				str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
