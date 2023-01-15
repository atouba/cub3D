/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:41:22 by atouba            #+#    #+#             */
/*   Updated: 2021/11/21 17:15:27 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
#include "libft.h"

// "hello" 
// start = 3
// len = 7
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*ans;

	i = 0;
	if (!s || start < 0 || len < 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		ans = malloc(sizeof(char));
		if (!ans)
			return (0);
		ans[0] = '\0';
		return (ans);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	ans = malloc(len + 1);
	if (!ans)
		return (0);
	while (len-- && s[start] != '\0')
		ans[i++] = s[start++];
	ans[i] = '\0';
	return (ans);
}

// int main()
// {
// 	// char *str = "i just want this part #############";
// 	size_t size = 100000;
//     char a[] = "hello";
//     printf("%s", ft_substr(a, 1, size));
// }