/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:42:22 by atouba            #+#    #+#             */
/*   Updated: 2021/11/11 13:23:15 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

static	int	is_last(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (0);
		s++;
	}
	return (1);
}

//// is it char *s or const char *s?
char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c && is_last(s + i + 1, c) == 1)
			return (s + i);
		i++;
	}
	if (c == s[i])
		return (s + i);
	return (0);
}
// int main()
// {
//     char a[] = "helclolalilmlnlssslaaliljfliflxxxxxx";
// //	printf("%c", ft_strrchr("haa", 'a'));
// 	printf("%s\n", ft_strrchr(a, 'a'));
//     printf("%s\n", strrchr(a, 'a'));
// }