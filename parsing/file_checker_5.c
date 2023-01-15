/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:36:33 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:41:07 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	general_check(t_map *map, int dx, int *buttom, int *head)
{
	char	**tmp;
	int		i;
	int		ret;

	i = 0;
	tmp = &map->map[dx];
	while (tmp[i])
	{
		ret = spaces_line(tmp[i]);
		if (ret == 2)
			return (ERROR);
		else if (ret == 0)
		{
			*head = i + dx;
			break ;
		}
		i++;
	}
	if (i == ft_strlen_tab(tmp))
		return (ERROR);
	return (buttom_map_check(tmp, dx, buttom));
}

char	**ft_strdup_tab(char **tab, int head, int buttom)
{
	char	**ret;
	int		i;

	i = 0;
	if (!tab)
		return (NULL);
	ret = malloc(sizeof(char *) * (buttom - head + 2));
	if (!ret)
	{
		printf("here!\n");
		return (NULL);
	}
	while (head <= buttom)
	{
		ret[i] = ft_strdup(tab[head]);
		head++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	many_players_check(char c, int *cnt)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (*cnt == 1)
		{
			printf("there is more then one player\n");
			return (ERROR);
		}
		*cnt += 1;
	}
	return (NO_ERROR);
}

int	unknown_byte(char c)
{
	if (c != '0' && is_wall(c) == NO && c != ' ' \
			&& c != 'N' && c != 'S' && c != 'E' && c != 'W')
	{
		printf("use only zeros and ones and One \
				character for the player [N, S, E, W]\n");
		return (ERROR);
	}
	return (NO_ERROR);
}

int	empty_line(char c)
{
	if (!c)
	{
		printf("empty line\n");
		return (ERROR);
	}
	return (NO_ERROR);
}
