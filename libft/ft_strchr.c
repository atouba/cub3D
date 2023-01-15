/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:42:16 by atouba            #+#    #+#             */
/*   Updated: 2021/11/09 13:30:55 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

// is it char *s or const char *s?
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (0);
}

// int main()
// {
//     char a[] = "helclo";
// 	char b[] = "helclo";
//     printf("%s\n", strchr(a, '\0'));
//     printf("%s", ft_strchr(b, '\0'));
// }