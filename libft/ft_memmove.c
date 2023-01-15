/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:56:01 by atouba            #+#    #+#             */
/*   Updated: 2021/11/17 11:39:12 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
// why unsigned char?
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	real_len;
	char	*d;
	char	*s;

	i = 0;
	real_len = len;
	d = (char *)dst;
	s = (char *)src;
	if (dst > src)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
	{
		ft_memcpy(d, s, len);
	}	
	return (dst);
}

// int main()
// {						   // "heyhey"  "heheyy"
// //	char a[7] = "heyhey";  // "eyheey"
// 	char b[7] = "heyhey";
// 	char c[7] = "heyhey";
// 	char dst[] = "eyhey";
// //	if (!(memcpy(a, a + 1, 3)))
// //		printf("%s\n", memmove(a, a + 3, 2));
// //	else
// 	char src[] = "thanks to @apellicc for this test !\r\n";
// 	char dst1[0xF0];
// 	char dst2[0xF0];
// 	int size = strlen(src);
// 	char *r1 = ft_memmove(dst1, src, size);
// 	char *r2 = memmove(dst2, src, size);
// 	//printf("%s", r1);
// //	printf("%s\n", memcpy(a, a + 3, 5));
// 	printf("%s", r2);
// }