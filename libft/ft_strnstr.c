/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:04:04 by atouba            #+#    #+#             */
/*   Updated: 2021/11/20 13:43:54 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

// ft_strlen is deleted, and I included the header file
static	int	is_here(const char *larger, const char *smaller)
{
	if (ft_strncmp(larger, smaller, ft_strlen(smaller)) == 0)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strncmp(needle, "", 1) == 0)
		return ((char *)(haystack));
	while (haystack[i])
	{
		if (len - i >= ft_strlen(needle))
		{
			if (haystack[i] == needle[0])
			{
				if (is_here(&(haystack[i]), needle) == 1)
					return ((char *)&(haystack[i]));
			}
			i++;
		}
		else
			break ;
	}
	return (0);
}

// int main()
// {
// 	char *s1 = "heeello buddy";
// 	char *s2 = "ll0 ";
// 	size_t max = strlen(s1);
// 	char *i1 = strnstr(s1, s2, 0);
// 	char *i2 = ft_strnstr(s1, s2, 0);
// 	printf("%s\n", s2);
//     printf("strnstr is    : %s\n", i1);
//     printf("ft_strnstr is : %s\n", i2);
// }