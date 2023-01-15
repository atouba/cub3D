/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:46:07 by atouba            #+#    #+#             */
/*   Updated: 2021/11/20 13:35:59 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

static	int	length(int n)
{
	int	i;

	if (n == -2147483648)
		return (11);
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	void	initialize(int *min, int *i, int *l, int n)
{
	*min = 0;
	*i = 0;
	*l = length(n);
}

static	void	init2(char *str, long long *big_n, int *min)
{
	*str = '-';
	*big_n = *big_n * (-1);
	*min = 1;
}

char	*ft_itoa(int n)
{
	char		*str;
	int			l;
	int			i;
	int			min;
	long long	big_n;

	initialize(&min, &i, &l, n);
	big_n = n;
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (0);
	if (n < 0)
		init2(str, &big_n, &min);
	l--;
	while (l >= min)
	{
		str[l] = (big_n % 10) + '0';
		big_n /= 10;
		l--;
	}
	str[length(n)] = '\0';
	return (str);
}
// for example, n == +6443 or ++6443?
// int main()
// {
//     int a = -214;
// 	// printf("%d ", length(n));
//     printf("%s", ft_itoa(a));
// }