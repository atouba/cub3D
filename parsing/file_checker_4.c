/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:20:21 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:22:26 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	test_north(char **map, int i, int j)
{
	if (!i || (j + 1 > (int)ft_strlen(map[i - 1])) || \
	map[i - 1][j] == ' ')
		return (NO);
	return (YES);
}

int	test_south(char **map, int i, int j)
{
	if ((i + 1 == ft_strlen_tab(map)) || (j + 1 > (int)ft_strlen(map[i + 1])) \
	|| (map[i + 1][j] == ' '))
		return (NO);
	return (YES);
}

int	test_east(char **map, int i, int j)
{
	if (j + 1 == (int)ft_strlen(map[i]) || map[i][j + 1] == ' ')
		return (NO);
	return (YES);
}

int	test_west(char **map, int i, int j)
{
	if (!j || map[i][j - 1] == ' ')
		return (NO);
	return (YES);
}

int	is_surrounded(char **map, int i, int j)
{
	if (test_north(map, i, j) == NO || \
			test_south(map, i, j) == NO \
	|| test_east(map, i, j) == NO || test_west(map, i, j) == NO)
		return (NO);
	return (YES);
}
