/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:47:19 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/28 13:50:11 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0 && n > -2147483648)
	{
		ft_putchar_fd(45, fd);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	if (n == -2147483648)
	{
		ft_putchar_fd(45, fd);
		ft_putnbr_fd(214748364, fd);
		ft_putchar_fd('8', fd);
	}
	else
	{
		if (n > 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
			ft_putchar_fd(n + 48, fd);
	}
}
