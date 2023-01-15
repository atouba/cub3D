/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:45:29 by atouba            #+#    #+#             */
/*   Updated: 2021/11/21 17:13:50 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	l;
	char	*ans;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (0);
	l = ft_strlen(s);
	ans = malloc(l + 1);
	if (ans)
	{
		ft_strlcpy(ans, s, ft_strlen(s));
		while (i < l)
		{
			ans[i] = f(i, s[i]);
			i++;
		}
		ans[i] = '\0';
	}
	return (ans);
}	

// int	main()
// {
// 	const char *a = "hello world";
// 	char (*func)(unsigned int, char) = f;
// 	printf("%s", ft_strmapi(a, func));
// 	printf("%ld", len(a));
// }