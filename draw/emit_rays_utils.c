/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:45:59 by atouba            #+#    #+#             */
/*   Updated: 2023/01/12 14:46:32 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

double	abs_double(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	is_between(double n, int min, int max)
{
	if (n >= min && n <= max)
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (YES);
	return (NO);
}
