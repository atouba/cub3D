/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_x_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:22:44 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:23:14 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_list	*file_to_list(int fd)
{
	t_list	*first;
	t_list	*last;

	first = 0;
	while (1)
	{
		ft_lstadd_back(&first, ft_lstnew(get_next_line(fd)));
		last = ft_lstlast(first);
		if (!last || !last->content)
			break ;
	}
	return (first);
}

char	**file_to_map(int fd)
{
	int		i;
	t_list	*first;
	t_list	*curr;
	char	**map;

	i = -1;
	first = file_to_list(fd);
	curr = first;
	map = ft_calloc(ft_lstsize(first) + 1, sizeof(char *));
	while (curr)
	{
		map[++i] = ft_strdup(curr->content);
		curr = curr->next;
	}
	map[i + 1] = 0;
	ft_lstclear(&first, free);
	return (map);
}

int	last_return(int *cnt, int d)
{
	*cnt *= d;
	return (NO_ERROR);
}
