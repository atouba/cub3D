/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:44:56 by atouba            #+#    #+#             */
/*   Updated: 2021/11/23 09:04:06 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ld;
	size_t	ls;

	ls = ft_strlen(src);
	j = 0;
	if (dstsize == 0 && !dst && src[0] == '\0')
		return (0);
	if (!dst && dstsize == 0)
		return (ls);
	i = ft_strlen(dst);
	ld = i;
	if (dstsize < ld)
		return (ls + dstsize);
	if (dstsize == 0)
		return (ls);
	while (src[j] && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ld + ls);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char d[13] = "hello ";
//     char *s = "there";
//     printf("%zu\n", ft_strlcat(d, s, 13));
//     printf("%s", d);
// }