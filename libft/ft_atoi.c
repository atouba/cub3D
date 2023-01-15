/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:41:49 by atouba            #+#    #+#             */
/*   Updated: 2021/11/20 13:34:58 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

static	int	isneg(char c, int *i)
{
	if (c == '-')
	{
		*i = *i + 1;
		return (-1);
	}
	if (c == '+')
		*i = *i + 1;
	return (1);
}

static	void	initialise(int *a, unsigned long long *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 1;
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	ans;
	int					sign;
	unsigned long long	max_long;

	max_long = 9223372036854775807;
	initialise(&i, &ans, &sign);
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		|| (str[i] >= '0' && str[i] <= '9'))
	{
		sign = isneg(str[i], &i);
		while (str[i] >= '0' && str[i] <= '9')
			ans = (ans * 10 + str[i++] - '0');
	}
	if (ans >= max_long + 1 && sign == -1)
		return (0);
	if (ans >= max_long)
		return (-1);
	return (ans * sign);
}

// 9223372036854775807
// int main()
// {
// 	char n[] = "9223372036854775808";	
// 	int i1 = atoi(n);
// 	int i2 = ft_atoi(n);
// 	int j = 0;
// 	printf("%d  ",i1);
// 	printf("%d\n",i2);
// }