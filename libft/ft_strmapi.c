/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 16:39:18 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/29 16:40:59 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		length;
	int		i;

	i = 0;
	if (s && f)
	{
		str = NULL;
		length = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (length + 1));
		if (str)
		{
			while (i < length)
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
