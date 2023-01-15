/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:45:07 by atouba            #+#    #+#             */
/*   Updated: 2021/11/08 19:49:34 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
// do we have to include string.h to use size_t keyword
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	if (i == n)
		i--;
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
// int main()
// {
//     char *s1 = "hihi";
//     char *s2 = "hihe";
//     int n = 4;
//     printf("%d ", memcmp(s1, s2, n));
//     printf("%d ", ft_memcmp(s1, s2, n));
// }
