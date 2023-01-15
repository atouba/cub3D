/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:46 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:20:11 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_strlen_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	ft_cmp(const char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (ERROR);
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (ERROR);
		i++;
	}
	if (!s1[i])
		return (NO_ERROR);
	return (ERROR);
}

int	extension_checker(char *name)
{
	if (!name)
		return (ERROR);
	while (*name)
	{
		if (*name == '.' && ft_cmp(name, ".cub") == NO_ERROR)
			return (NO_ERROR);
		name++;
	}
	return (ERROR);
}

int	numbers_checker(char *str, t_info *info, char c)
{
	char	**tab;
	int		ret;

	tab = ft_split(str, ',');
	if (!tab)
		return (ERROR);
	if (ft_strlen_tab(tab) != 3)
	{
		free_tab(tab);
		return (ERROR);
	}
	ret = arguments_checker(tab, info, c);
	free_tab(tab);
	return (ret);
}
