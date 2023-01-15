/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:41:38 by atouba            #+#    #+#             */
/*   Updated: 2021/11/13 09:51:55 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ans;

	i = 0;
	if (!s1)
		return (0);
	ans = (char *)malloc(ft_strlen(s1) + 1);
	if (!ans)
		return (0);
	while (s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
// int main()
// {
//     char *a = "hello";
//     printf("%s", ft_strdup(a));
// }
