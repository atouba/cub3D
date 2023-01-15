/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:23:24 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:30:04 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	last_check(char **map, int i, int j)
{
	if (is_wall(map[i][j]) == NO && map[i][j] != ' ' \
			&& is_surrounded(map, i, j) == NO)
	{
		printf("zeros needs to be surronded by ones\n");
		return (ERROR);
	}
	return (NO_ERROR);
}

int	map_bytes_checker(char **map)
{
	int	i;
	int	cnt;
	int	j;

	cnt = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		if (empty_line(map[i][j]) == ERROR)
			return (ERROR);
		while (map[i][j])
		{
			if (unknown_byte(map[i][j]) == ERROR \
			|| many_players_check(map[i][j], &cnt) == ERROR \
			|| last_check(map, i, j) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	if (!cnt)
		return (ERROR);
	return (NO_ERROR);
}

int	map_part_checker(t_map *map, int index)
{
	int		buttom;
	int		head;
	char	**tmp;

	if (general_check(map, index, &buttom, &head) == ERROR)
		return (ERROR);
	tmp = map->map;
	map->map = ft_strdup_tab(tmp, head, buttom);
	if (!map->map)
		return (ERROR);
	free_tab(tmp);
	return (map_bytes_checker(map->map));
}

int	last_last_check(int i, int j, t_map *map, t_info *info)
{
	if (j == 6 && f_part_checker(map->info, info) == NO_ERROR \
			&& map_part_checker(map, i + 1) == NO_ERROR)
		return (NO_ERROR);
	return (ERROR);
}

int	parts_checker(t_map *map, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->info = malloc(sizeof(char *) * 7);
	while (map->map[i])
	{
		if (spaces_line(map->map[i]) == YES)
			return (ERROR);
		else if (map->map[i][0])
		{
			map->info[j] = ft_strdup(map->map[i]);
			j++;
		}
		if (j == 6)
		{
			map->info[j] = 0;
			break ;
		}
		i++;
	}
	return (last_last_check(i, j, map, info));
}
