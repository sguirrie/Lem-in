/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:36:37 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/29 14:51:30 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				str[i] = f(s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
