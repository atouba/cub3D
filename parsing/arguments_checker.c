/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:09:31 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:16:36 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_atoii(const char *str)
{
	int				i;
	int				signe;
	unsigned int	nbr;

	signe = 1;
	i = 0;
	nbr = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = 10 * nbr + (str[i] - '0');
		i++;
	}
	return (nbr * signe);
}

int	arg_is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] > '9' || arg[i] < '0' || i > 3)
			return (0);
		i++;
	}
	return (1337);
}

int	arguments_checker(char *argv[], t_info *info, char c)
{
	int	i;
	int	tmp;

	i = 0;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (ERROR);
		tmp = ft_atoii(argv[i]);
		if (tmp < 0 || tmp > 255)
			return (ERROR);
		if (c == 'C')
			info->c_colors[i] = tmp;
		else if (c == 'F')
			info->f_colors[i] = tmp;
		i++;
	}
	return (NO_ERROR);
}
