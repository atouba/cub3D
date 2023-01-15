/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:29:33 by atouba            #+#    #+#             */
/*   Updated: 2021/12/13 20:24:21 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strdup_before_back_slach_n(char *s1)
{
	int		i;
	char	*ans;

	i = 0;
	if (!s1)
		return (0);
	ans = malloc(ft__strlen(s1, 0) + 1);
	if (!ans)
		return (0);
	while (s1[i] && s1[i] != '\n')
	{
		ans[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		ans[i] = '\n';
		ans[i + 1] = 0;
	}
	else
		ans[i] = 0;
	return (ans);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ans;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft__strdup("");
	ans = malloc(sizeof(char) * (ft__strlen(s1, 1) + ft__strlen(s2, 1) + 1));
	if (!ans)
		return (0);
	while (s1[++i] != '\0')
		ans[i] = s1[i];
	while (s2[j] != '\0')
		ans[i++] = s2[j++];
	ans[i] = '\0';
	if (ft_strcmp(s1, "") == 0)
	{
		free(s1);
		s1 = 0;
	}
	return (ans);
}

int	fill_temp(char **temp, int fd)
{
	char	*ans;
	int		r;
	char	*hold;

	r = 1;
	ans = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (r != 0)
	{
		r = read(fd, ans, BUFFER_SIZE);
		if (r <= 0)
		{
			free(ans);
			return (0);
		}
		ans[r] = 0;
		hold = *temp;
		*temp = ft_strjoin(hold, ans);
		free(hold);
		if (*temp && (ft_strchr(*temp, '\n') || *temp[0] == '\n'))
		{
			free(ans);
			break ;
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*ans;
	char		*hold;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	n = fill_temp(&temp, fd);
	if (!n && !temp)
		return (0);
	ans = strdup_before_back_slach_n(temp);
	if ((ft_strchr(temp, '\n') || temp[0] == '\n')
		&& temp[ft_strchr(temp, '\n') + 1] != '\0')
	{
		hold = ft__strdup(after_back_slach_n(temp));
		free(temp);
		temp = ft__strdup(hold);
		free(hold);
	}
	else
		ft_free(&temp);
	if (n == 0 && ft_strcmp(ans, "") == 0)
		return (0);
	return (ans);
}
