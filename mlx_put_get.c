/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:08:27 by atouba            #+#    #+#             */
/*   Updated: 2023/01/12 20:15:58 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	convert_to_range(double old_min, double old_max, double old_value)
{
	double	new_value;
	double	new_min;
	double	new_max;

	new_min = 0;
	new_max = 32;
	new_value = (((old_value - old_min) * (new_max - new_min))
			/ (old_max - old_min)) + new_min;
	return (new_value);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || y <= 0 || x >= 800 || y >= 600)
		return ;
	dst = (data->addr + (y * data->line_length + x * \
	(data->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = (data->addr + (y * data->line_length + x * \
	(data->bits_per_pixel / 8)));
	return (*(unsigned int *)dst);
}

int	close_me(void)
{
	exit(0);
	return (1337);
}
