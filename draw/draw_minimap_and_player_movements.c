/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_and_player_movements.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:22:27 by atouba            #+#    #+#             */
/*   Updated: 2023/01/12 19:48:11 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

double	starting_angle(char c)
{
	if (c == 'N')
		return (90);
	if (c == 'W')
		return (180);
	if (c == 'S')
		return (270);
	else
		return (0);
}

int	move_player_possiblity(t_map *map, double angle)
{
	t_dda	dda;

	dda = dda_struct(map, angle);
	if (dda.distance <= 12)
		return (0);
	return (1);
}

void	rotate(t_map *map, int angle)
{
	int	a;

	map->rotation_angle += angle;
	if (map->black_img)
		mlx_destroy_image(map->mlx.mlx, map->black_img);
	map->black_img = mlx_xpm_file_to_image(map->mlx.mlx, "images/black.xpm",
			&a, &a);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->black_img, 0, 0);
	emit_rays(map, map->mlx);
}

void	go_forward_backward(t_map *map, int angle)
{
	int		a;
	double	cos_value;
	double	sin_value;

	cos_value = cos((double)(angle * M_PI / 180));
	sin_value = -1 * sin((double)(angle * M_PI / 180));
	if (!move_player_possiblity(map, -1 * angle))
		return ;
	map->player_x += (int)(cos_value * 6);
	map->player_y += (int)(sin_value * 6);
	if (map->black_img)
		mlx_destroy_image(map->mlx.mlx, map->black_img);
	map->black_img = mlx_xpm_file_to_image(map->mlx.mlx, "images/black.xpm",
			&a, &a);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->black_img, 0, 0);
	emit_rays(map, map->mlx);
}

int	move_player_minimap(int keycode, t_map *map)
{
	if (keycode == 53)
		close_me();
	else if (keycode == 124)
		rotate(map, -3);
	else if (keycode == 123)
		rotate(map, 3);
	else if (keycode == 13)
		go_forward_backward(map, map->rotation_angle);
	else if (keycode == 1)
		go_forward_backward(map, map->rotation_angle + 180);
	else if (keycode == 0)
		go_forward_backward(map, map->rotation_angle + 90);
	else if (keycode == 2)
		go_forward_backward(map, map->rotation_angle - 90);
	return (0);
}
