/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:18 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 15:51:47 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_value(int signe, t_map map, double *value, char c)
{
	if (c == 'y')
	{
		if (signe == 1)
			*value = (int)(map.player_y / 32) *32 + 32;
		else if (signe == -1)
			*value = (int)(map.player_y / 32) *32;
		else
			*value = map.player_y;
	}
	else
	{
		if (signe == 1)
			*value = (int)(map.player_x / 32) *32 + 32;
		else if (signe == -1)
			*value = (int)(map.player_x / 32) *32;
		else
			*value = map.player_x;
	}
}

void	horr_inter(t_map map, double angle, double *xf, double *yf)
{
	int		signe_x;
	int		signe_y;
	double	abs_angle;

	abs_angle = abs_num(tan(angle * PI / 180));
	signs_movement(angle, &signe_x, &signe_y);
	init_value(signe_y, map, yf, 'y');
	if (signe_x)
		*xf = map.player_x + signe_x * ((int)abs_num(*yf - \
					map.player_y) / abs_angle);
	else
		*xf = map.player_x;
	while (map_range(map, xf, yf) == NO && ((fmod(*xf, 32) \
	&& is_wall(map.map[(int)(*yf / 32) - 1][(int)(*xf / 32)]) == NO \
	&& is_wall(map.map[(int)(*yf / 32)][(int)(*xf / 32)]) == NO) \
	|| (!fmod(*xf, 32) && \
	is_wall(map.map[(int)(*yf / 32)][(int)(*xf / 32) + signe_x]) == NO \
	&& is_wall(map.map[(int)(*yf / 32) + signe_y][(int)(*xf / 32)]) == NO)))
	{
		*yf += signe_y * 32;
		if (signe_x)
			*xf += signe_x * (32 / abs_angle);
	}
}

void	ver_inter(t_map map, double angle, double *xf, double *yf)
{
	int		signe_x;
	int		signe_y;
	double	abs_angle;

	abs_angle = abs_num(tan(angle * PI / 180));
	signs_movement(angle, &signe_x, &signe_y);
	init_value(signe_x, map, xf, 'x');
	if (signe_y)
		*yf = map.player_y + signe_y * (abs_num(*xf \
					- map.player_x) * abs_angle);
	else
		*yf = map.player_y;
	while (map_range(map, xf, yf) == NO && ((fmod(*yf, 32) \
	&& is_wall(map.map[(int)(*yf / 32)][(int)(*xf / 32) - 1]) == NO \
	&& is_wall(map.map[(int)(*yf / 32)][(int)(*xf / 32)]) == NO) || \
	(!(fmod(*yf, 32)) && \
	is_wall(map.map[(int)(*yf / 32)][(int)(*xf / 32) + signe_x]) == NO \
	&& is_wall(map.map[(int)(*yf / 32) + signe_y][(int)(*xf / 32)]) == NO)))
	{
		*xf += signe_x * 32;
		if (signe_y)
			*yf += signe_y * (32 * abs_angle);
	}
}

t_dda	dda_return(int x, int y, int orio, double distance)
{
	t_dda	dda;

	dda.x_collision = x;
	dda.y_collision = y;
	dda.orientation = orio;
	dda.distance = distance;
	return (dda);
}

t_dda	dda_struct(t_map *map, double angle)
{
	t_var	var;

	angle = fmod(angle, 360);
	if (angle == -270 || angle == 270 \
	|| angle == -90 || angle == 90)
	{
		horr_inter(*map, angle, &var.hxf, &var.hyf);
		return (dda_return(var.hxf, var.hyf, HORIZENTAL, \
					abs_num(map->player_y - var.hyf)));
	}
	else if (angle == 180 || angle == -180 || angle == 0)
	{
		ver_inter(*map, angle, &var.vxf, &var.vyf);
		return (dda_return(var.vxf, var.vyf, VERTICAL, \
					abs_num(map->player_x - var.vxf)));
	}
	horr_inter(*map, angle, &var.hxf, &var.hyf);
	var.hor_distance = abs_num((map->player_y - var.hyf) / \
			sin(angle * PI / 180));
	ver_inter(*map, angle, &var.vxf, &var.vyf);
	var.ver_distance = abs_num((map->player_x - var.vxf) / \
			cos(angle * PI / 180));
	if (var.hor_distance < var.ver_distance)
		return (dda_return(var.hxf, var.hyf, HORIZENTAL, var.hor_distance));
	return (dda_return(var.vxf, var.vyf, VERTICAL, var.ver_distance));
}
