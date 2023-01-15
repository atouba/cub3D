/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:41:21 by atouba            #+#    #+#             */
/*   Updated: 2021/11/19 09:50:38 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"
//#include <stdio.h>
//ft_strlen is deleted, header is added
// what if dstsize >= len of dest?
// delete restrict

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == 0)
		return (i);
	while (j < dstsize - 1 && src[j] != 0)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
//
// int main()
// {
// 	char a[38];

// 	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
// 	// char src1[] = "coucou";
// 	char b[38];
// 	// memset(b, 'B', 10);
// 	printf("%ld ", ft_strlcpy(b, str, 37));
// 	printf("%ld\n", strlcpy(a, str, 37));
// 	printf("%s ", b);
// 	printf("%s\n", a);
// 	// printf("\n%s",  );
//     // char d[6];
//     // //char c[6];
//     // char s[] = "hello";
//     // //size_t l = strlcpy(d, s, 5);
// 	// // printf("%ld\n",strlcpy(d, s, 5));
//     // printf("%ld\n",strlcpy(d, s, 1));
//     // //printf("%s\n",d);
//     // printf("\n%zu\n", ft_strlcpy(d, s, 2));
//     // // printf("%s\n", c);
// }