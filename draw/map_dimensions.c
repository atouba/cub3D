/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:47:06 by atouba            #+#    #+#             */
/*   Updated: 2023/01/12 14:50:24 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	max_width(char **map)
{
	int	i;
	int	max_len;
	int	tmp;

	i = 1;
	max_len = ft_strlen(map[0]);
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (max_len < tmp)
			max_len = tmp;
		i++;
	}
	return (max_len);
}

char	*change_it(t_map *map, int i)
{
	char	*ret;
	int		j;

	j = 0;
	ret = malloc(sizeof(char) * (map->width + 1));
	while (map->map[i][j])
	{
		ret[j] = map->map[i][j];
		j++;
	}
	while (j < map->width)
	{
		ret[j] = '1';
		j++;
	}
	ret[j] = 0;
	return (ret);
}

void	rectangle_map(t_map *map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != (size_t)map->width)
		{
			tmp = map->map[i];
			map->map[i] = change_it(map, i);
			free(tmp);
		}
		i++;
	}
}
