/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:53:56 by atouba            #+#    #+#             */
/*   Updated: 2023/01/12 20:09:10 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	no_new_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '\n')
				map->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	spaces_to_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
				map->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	check_tile_size(t_height_width a, t_height_width b,
						t_height_width c, t_height_width d)
{
	if (a.h != 32 || a.w != 32
		|| b.h != 32 || b.w != 32
		|| c.h != 32 || c.w != 32
		|| d.h != 32 || d.w != 32)
	{
		printf("Error:\nThe wall textures images have to have\
		32px as tile size\n");
		exit(1);
	}
}

void	lets_init_all(t_map *map, t_info info)
{
	map->rot_key = 0;
	map->fov = 60.0;
	map->data.img = mlx_new_image(map->mlx.mlx, 800, 600);
	map->data.addr = mlx_get_data_addr(map->data.img,
			&map->data.bits_per_pixel, &map->data.line_length,
			&map->data.endian);
	spaces_to_walls(map);
	map->height = ft_strlen_tab(map->map);
	map->width = max_width(map->map);
	rectangle_map(map);
	map->mlx.mlx = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.mlx, 800,
			600, "cub3D");
	init_textures_and_angle(map, info);
	init_map(map);
	emit_rays(map, map->mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	t_info	info;
	t_map	map;

	if (ac != 2 || (ac == 2 && extension_checker(av[1]) == ERROR))
	{
		printf("Error:\nRun it in this way : ./cub3D [file_name.cub]");
		return (ERROR);
	}
	fd = open(av[1], O_RDWR);
	map.map = file_to_map(fd);
	if (!map.map)
		return (ERROR);
	no_new_line(&map);
	if (parts_checker(&map, &info) == ERROR)
	{
		printf("Error:\nInvalide map");
		return (ERROR);
	}
	lets_init_all(&map, info);
	mlx_hook(map.mlx.win, 2, 1L << 0, move_player_minimap, &map);
	mlx_hook(map.mlx.win, 17, 1L << 2, close_me, NULL);
	mlx_loop(map.mlx.mlx);
	return (0);
}
