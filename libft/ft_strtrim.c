/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 01:54:10 by sguirrie          #+#    #+#             */
/*   Updated: 2013/12/03 13:49:25 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		start;

	start = 0;
	len = 0;
	if (s)
	{
		while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
				&& s[start] != 0)
			start++;
		len = ft_strlen(s) - 1;
		if (start == (len + 1))
			return (ft_strdup(""));
		while (len >= 0 && (s[len] == ' ' || s[len] == '\n'
				|| s[len] == '\t'))
			len--;
		len = len - start;
		len++;
		return (ft_strsub(s, start, len));
	}
	return (NULL);
}
