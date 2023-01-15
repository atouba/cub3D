/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:43:36 by atouba            #+#    #+#             */
/*   Updated: 2021/11/21 17:10:03 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// "6284"

void	ft_putnbr_fd(int n, int fd)
{
	long long	res;

	res = n;
	if (fd < 0)
		return ;
	if (res >= 0 && res <= 9)
	{
		ft_putchar_fd(res + '0', fd);
	}
	if (res < 0)
	{
		ft_putchar_fd('-', fd);
		res *= -1;
		if (res >= 0 && res <= 9)
		{
			ft_putchar_fd(res + '0', fd);
			return ;
		}
	}
	if (res >= 10)
	{
		ft_putnbr_fd(res / 10, fd);
		ft_putchar_fd((res % 10) + '0', fd);
	}
}
