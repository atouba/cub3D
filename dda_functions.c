/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:14:26 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:15:28 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	abs_num(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	is_wall(char c)
{
	if (c == '1')
		return (YES);
	return (NO);
}

void	signs_movement(double angle, int *signe_x, int *signe_y)
{
	if ((angle > 0 && angle < 180) || (angle < -180))
		*signe_y = 1;
	else if (fmod(angle, 180))
		*signe_y = -1;
	else
		*signe_y = 0;
	if ((angle > 90 && angle < 270) || (angle > -270 && angle < -90))
		*signe_x = -1;
	else if (!fmod(angle, 90) && fmod(angle, 180))
		*signe_x = 0;
	else
		*signe_x = 1;
}

int	map_range(t_map map, double *xf, double *yf)
{
	if (*xf <= (map.width * 32) && \
			*yf <= (map.height * 32) && *yf >= 0 && *xf >= 0)
		return (NO);
	return (YES);
}
