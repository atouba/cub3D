/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:47:48 by atouba            #+#    #+#             */
/*   Updated: 2021/11/23 09:03:20 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wcount(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	if (s == 0)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	ft_free(char **ptr, int wc)
{
	int	i;

	i = wc + 1;
	while (i > 0)
	{
		free(ptr[i]);
		i--;
	}
}

static char	*ft_strndup(const char *s, char **ptr, size_t len, char c)
{
	char	*p;
	size_t	i;
	int		wc;

	wc = wcount(s, c);
	i = 0;
	p = (char *)malloc(len * sizeof(char) + 1);
	if (p == NULL)
	{
		ft_free(ptr, wc);
		free(ptr);
	}
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	ft_zero(int *i, int *j, int *k, int *len)
{
	*i = 0;
	*j = -1;
	*len = 0;
	*k = 0;
}

char	**ft_split(char const *s, char c )
{
	int		i;
	int		j;
	int		len;
	char	**ptr;
	int		k;

	ft_zero(&i, &j, &k, &len);
	ptr = (char **)malloc((wcount(s, c) + 1) * sizeof(char *));
	if (!(ptr))
		return (NULL);
	while (++j < wcount(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		k = i - len;
		ptr[j] = ft_strndup(&s[k], ptr, len, c);
		len = 0;
	}
	ptr[j] = 0;
	return (ptr);
}

// #include <stdio.h>
// int main()
// {
// 	char **a = ft_split(0, 0);
// 	int i = 0;
// 	while (a[i])
// 		printf("%s ", a[i++]);
// }