/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:30:24 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:36:24 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	repeted_words_check(char **info, char *tab, int *cnt, int d)
{
	*info = ft_strdup(tab);
	*cnt *= d;
	return (NO_ERROR);
}

int	words_checker(char **str, int *cnt, t_info *info)
{
	int	i;

	i = 0;
	if (!str || ft_strlen_tab(str) != 2)
		return (ERROR);
	if (ft_cmp(str[0], "NO") == NO_ERROR && (*cnt % 2))
		return (repeted_words_check(&info->no_path, str[1], cnt, 2));
	else if (ft_cmp(str[0], "SO") == NO_ERROR && (*cnt % 3))
		return (repeted_words_check(&info->so_path, str[1], cnt, 3));
	else if (ft_cmp(str[0], "WE") == NO_ERROR && (*cnt % 5))
		return (repeted_words_check(&info->we_path, str[1], cnt, 5));
	else if (ft_cmp(str[0], "EA") == NO_ERROR && (*cnt % 7))
		return (repeted_words_check(&info->ea_path, str[1], cnt, 7));
	else if (ft_cmp(str[0], "F") == NO_ERROR && (*cnt % 11) \
			&& numbers_checker(str[1], info, 'F') == NO_ERROR)
		return (last_return(cnt, 11));
	else if (ft_cmp(str[0], "C") == NO_ERROR && (*cnt % 13) \
			&& numbers_checker(str[1], info, 'C') == NO_ERROR)
		return (last_return(cnt, 13));
	return (ERROR);
}

int	f_part_checker(char **map, t_info *info)
{
	int		i;
	char	**tmp;
	int		cnt;

	i = 0;
	cnt = 1;
	info->c_colors = malloc(sizeof(int) * 3);
	info->f_colors = malloc(sizeof(int) * 3);
	if (!info->c_colors || !info->f_colors)
		return (ERROR);
	while (map[i])
	{
		tmp = ft_split(map[i], ' ');
		if (words_checker(tmp, &cnt, info) == ERROR)
		{
			free_tab(tmp);
			return (ERROR);
		}
		free_tab(tmp);
		i++;
	}
	return (NO_ERROR);
}

int	spaces_line(char *line)
{
	int	i;

	i = 0;
	if (!line[i])
		return (1);
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (2);
}

int	buttom_map_check(char **tmp, int dx, int *buttom)
{
	int	ret;
	int	i;

	i = ft_strlen_tab(tmp) - 1;
	while (i)
	{
		ret = spaces_line(tmp[i]);
		if (ret == 2)
			return (ERROR);
		else if (ret == 0)
		{
			*buttom = i + dx;
			break ;
		}
		i--;
	}
	return (NO_ERROR);
}
