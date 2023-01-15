/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:11:23 by atouba            #+#    #+#             */
/*   Updated: 2021/11/20 09:17:03 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == 0 && dst == 0)
		return (0);
	if (dst == src)
		return (dst);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
// this function is faulse
// int main()
// {						   // "heyhey"
// 	//har a[] = "anasloz1337hey";  // "eyheey"
// 	//char b[] = "anasloz1337hey";
// //	char c[7] = "heyhey";
// //	if (!(memcpy(a, a + 1, 3)))
// 		// printf("%s\n", memcpy(a + 2, a, 5));
// //	else
// 	//printf("%s\n\n", memmove(c, c + 3, 5));
// 	printf("%s\n", ft_memcpy("A", "A", 1));
// 	//printf("%s\n", ft_memcpy(b + 2, b, 5));
// }
