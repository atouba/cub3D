/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:06:07 by atouba            #+#    #+#             */
/*   Updated: 2023/01/12 20:06:40 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_player(map->map[i][j]) == YES)
			{
				map->player_x = j * 32 + 16;
				map->player_y = i * 32 + 16;
				map->rotation_angle = starting_angle(map->map[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	init_textures_images(t_map *map, t_info info)
{
	t_height_width	a;
	t_height_width	b;
	t_height_width	c;
	t_height_width	d;

	map->black_img = mlx_xpm_file_to_image(map->mlx.mlx, "images/black.xpm",
			&a.w, &a.h);
	map->textures.north.img = mlx_xpm_file_to_image(map->mlx.mlx, info.no_path,
			&a.w, &a.h);
	map->textures.east.img = mlx_xpm_file_to_image(map->mlx.mlx, info.ea_path,
			&b.w, &b.h);
	map->textures.south.img = mlx_xpm_file_to_image(map->mlx.mlx, info.so_path,
			&c.w, &c.h);
	map->textures.west.img = mlx_xpm_file_to_image(map->mlx.mlx, info.we_path,
			&d.w, &d.h);
	check_tile_size(a, b, c, d);
}

void	init_textures_addresses(t_map *map)
{
	map->textures.north.addr = mlx_get_data_addr(map->textures.north.img,
			&map->textures.north.bits_per_pixel,
			&map->textures.north.line_length,
			&map->textures.north.endian);
	map->textures.east.addr = mlx_get_data_addr(map->textures.east.img,
			&map->textures.east.bits_per_pixel,
			&map->textures.east.line_length,
			&map->textures.east.endian);
	map->textures.south.addr = mlx_get_data_addr(map->textures.south.img,
			&map->textures.south.bits_per_pixel,
			&map->textures.south.line_length,
			&map->textures.south.endian);
	map->textures.west.addr = mlx_get_data_addr(map->textures.west.img,
			&map->textures.west.bits_per_pixel,
			&map->textures.west.line_length,
			&map->textures.west.endian);
}

void	init_textures_and_angle(t_map *map, t_info info)
{
	init_textures_images(map, info);
	if (!map->black_img || !map->textures.north.img || !map->textures.east.img
		|| !map->textures.south.img || !map->textures.west.img)
	{
		printf("Error:\nconversion from xpm to mlx image failed\n");
		exit(0);
	}
	init_textures_addresses(map);
	map->textures.floor_color = info.f_colors[0] * 256 * 256 + \
	info.f_colors[1] * 256 + info.f_colors[2];
	map->textures.ceilling_color = info.c_colors[0] * 256 * 256 + \
	info.c_colors[1] * 256 + info.c_colors[2];
}
