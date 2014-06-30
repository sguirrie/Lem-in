/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:45:33 by sguirrie          #+#    #+#             */
/*   Updated: 2013/12/03 13:54:15 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			while (len--)
				str[i++] = s[start++];
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
