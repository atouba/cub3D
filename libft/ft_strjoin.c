/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:52:40 by atouba            #+#    #+#             */
/*   Updated: 2021/11/21 14:42:35 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ans;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	ans = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ans)
		return (0);
	while (s1[i] != '\0')
	{
		ans[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ans[i] = s2[j];
		i++;
		j++;
	}
	ans[i] = '\0';
	return (ans);
}

// int main()
// {
// 	char a[] = "f";
// 	char b[] = "";
// 	printf("%s", ft_strjoin(a, b));
// }