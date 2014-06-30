/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:42:18 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/28 16:02:55 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_build_string(int n, int *i, int *sign, char *str);

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				sign[1];
	unsigned int	ui;

	sign[0] = 1;
	i = 1;
	ui = n;
	str = ft_build_string(n, &i, sign, str);
	if (str)
	{
		if (sign[0] == -1)
			ui = n * -1;
		str[i] = '\0';
		while (--i >= 0)
		{
			str[i] = ui % 10 + '0';
			ui = ui / 10;
		}
		if (sign[0] == -1)
			str[0] = '-';
	}
	return (str);
}

char			*ft_build_string(int n, int *i, int *sign, char *str)
{
	int			length;

	length = n;
	if (n < 0)
	{
		sign[0] = -1;
		*i = 2;
	}
	while ((length = length / 10) != 0)
		(*i)++;
	str = (char *)malloc(sizeof(char) * (*i + 1));
	return (str);
}
