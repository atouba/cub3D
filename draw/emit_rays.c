/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:03:13 by atouba            #+#    #+#             */
/*   Updated: 2023/01/12 19:31:01 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_data	*texture(t_map *map, int ray_index)
{
	t_data	*struc;
	double	angle;

	angle = map->rays[ray_index].angle;
	if ((is_between(angle, 90, 270) || is_between(angle, -270, -90))
		&& map->rays[ray_index].orientation == VERTICAL)
		struc = &map->textures.east;
	if (!(is_between(angle, 90, 270) || is_between(angle, -270, -90))
		&& map->rays[ray_index].orientation == VERTICAL)
		struc = &map->textures.west;
	if ((is_between(angle, 0, 180) || is_between(angle, -360, -180))
		&& map->rays[ray_index].orientation == HORIZENTAL)
		struc = &map->textures.south;
	if (!(is_between(angle, 0, 180) || is_between(angle, -360, -180))
		&& map->rays[ray_index].orientation == HORIZENTAL)
		struc = &map->textures.north;
	return (struc);
}

void	draw(t_map *map, int ray_index, t_data *texture, int x_image)
{
	int	i;
	int	y_image;
	int	color;
	int	min;
	int	max;

	i = -1;
	min = 300 - map->rays[ray_index].wall_height / 2;
	max = 300 + map->rays[ray_index].wall_height / 2;
	while (++i < min)
		my_mlx_pixel_put(&map->data, ray_index, i, \
		map->textures.ceilling_color);
	while (i < max)
	{
		y_image = convert_to_range(min, max, i);
		color = my_mlx_pixel_get(texture, x_image, y_image);
		my_mlx_pixel_put(&map->data, ray_index, i, color);
		i++;
	}
	while (i < 600)
	{
		my_mlx_pixel_put(&map->data, ray_index, i, \
		map->textures.floor_color);
		i++;
	}
}

void	cast_rays(t_map *map)
{
	int		x_image;
	int		ray_index;
	t_data	*struc;

	ray_index = 0;
	while (ray_index < 800)
	{
		map->rays[ray_index].angle = fmod(map->rays[ray_index].angle, 360);
		struc = texture(map, ray_index);
		if (map->rays[ray_index].orientation == HORIZENTAL)
			x_image = map->rays[ray_index].x_coll % 32;
		else
			x_image = map->rays[ray_index].y_coll % 32;
		draw(map, ray_index, struc, x_image);
		ray_index++;
	}
}

void	effuse_ray(t_map *map, double angle,
				int ray_index, double original_angle)
{
	double			ray_distance;
	double			projected_wall_height;
	double			distance_to_the_view;
	t_dda			dda;

	dda = dda_struct(map, angle * -1);
	distance_to_the_view = 400.0 / tan(30 * M_PI / 180);
	ray_distance = dda.distance;
	ray_distance *= fabs(cos((double)((double)(angle - original_angle)
					*M_PI / 180)));
	projected_wall_height = 32.0 * distance_to_the_view / ray_distance;
	map->rays[ray_index].ray_distance = dda.distance;
	map->rays[ray_index].x_coll = dda.x_collision;
	map->rays[ray_index].y_coll = dda.y_collision;
	map->rays[ray_index].orientation = dda.orientation;
	map->rays[ray_index].wall_height = projected_wall_height;
	map->rays[ray_index].angle = angle;
}

void	emit_rays(t_map *map, t_mlx mlx)
{
	double	min_angle;
	int		max_angle;
	int		ray_index;

	if (!mlx.mlx)
		return ;
	ray_index = 0;
	min_angle = map->rotation_angle + 30;
	max_angle = map->rotation_angle - 30;
	while (min_angle > max_angle && ray_index < 800)
	{
		effuse_ray(map, min_angle, ray_index, map->rotation_angle);
		min_angle -= 60.0 / 800.0;
		ray_index++;
	}
	cast_rays(map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, map->data.img, 0, 0);
}
