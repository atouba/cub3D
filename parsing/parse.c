/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:41:11 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:42:13 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_char_there(char *line, char c)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == c)
			return (YES);
	}
	return (NO);
}

int	is_consecutive_c(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != c && str[i] != '\n')
			return (NO);
	}
	return (YES);
}

int	char_is_start_end(char *str, char c)
{
	int	end;

	end = ft_strlen(str) - 1;
	if (str[end] == '\n')
		end--;
	if (str[0] == c && str[end] == c)
		return (YES);
	return (NO);
}
