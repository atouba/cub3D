/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:42:41 by atouba            #+#    #+#             */
/*   Updated: 2021/11/11 10:03:47 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
// int main(void)
// {
//     // char s[] = "anas douib 133u7";
//     // char s2[] = "anas douib 133u7";
//     char s3[] = {0, 1, 9, 6, 5, 3, 32, 65, 84, 2, 32, 81, 2};

//     char c = 'b';

//     // size_t n = sizeof(s) / sizeof(char);
//     // size_t n2 = sizeof(s2) / sizeof(char);

//     char * sp = memchr(s3, 9 + 256, 42);
//     printf("memchr : %s\n", sp);

//     char * s2p = ft_memchr(s3, 9 + 256, 42);
//     printf("ft_memchr : %s\n", s2p);

//     return 0;
// }