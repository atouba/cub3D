/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:31:12 by aabouzid          #+#    #+#             */
/*   Updated: 2023/01/12 16:46:15 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define ERROR -1
# define NO_ERROR 0
# define NO 1
# define YES 2
# define NORTH 3
# define EAST 4
# define SOUTH 5
# define WEST 6
# define HORIZENTAL 7
# define VERTICAL 8
# define PI 3.142857
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_info
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		*f_colors;
	int		*c_colors;
}	t_info;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_ray
{
	int		x_coll;
	int		y_coll;
	int		ray_distance;
	int		wall_height;
	int		orientation;
	char	wall_char;
	double	angle;
}	t_ray;

typedef struct s_textures
{
	t_data	north;
	t_data	east;
	t_data	south;
	t_data	west;
	int		ceilling_color;
	int		floor_color;
}	t_textures;

typedef struct s_map
{
	t_data		data;
	t_mlx		mlx;
	char		**info;
	char		**map;
	int			width;
	int			height;
	void		*black_img;
	t_textures	textures;
	int			player_x;
	int			player_y;
	int			rotation_angle;
	int			rot_key;
	double		fov;
	t_ray		rays[800];
}	t_map;

typedef struct s_coordinate
{
	double	x;
	double	y;
}	t_coordinate;

typedef struct s_height_width
{
	int	w;
	int	h;
}	t_height_width;

typedef struct s_dda
{
	int		x_collision;
	int		y_collision;
	int		orientation;
	double	distance;
}	t_dda;

typedef struct s_var
{
	double	hxf;
	double	hyf;
	double	vxf;
	double	vyf;
	double	hor_distance;
	double	ver_distance;
}	t_var;

void			free_2d_c_arr(char **strs);
char			**file_to_map(int fd);
int				parts_checker(t_map *map, t_info *info);
int				extension_checker(char *name);
int				arguments_checker(char *argv[], t_info *info, char c);
int				spaces_line(char *line);
int				ft_strlen_tab(char **str);
int				max_width(char **map);
int				height(char **map);
void			draw_2d_map(t_mlx mlx, t_map *map);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				close_me(void);
int				move_player_minimap(int keycode, t_map *map);
double			player_rotation(char c);
double			starting_angle(char c);
void			emit_rays(t_map *map, t_mlx mlx);
t_coordinate	dda(t_map *map, double angle);
unsigned int	my_mlx_pixel_get(t_data *data, int x, int y);
double			convert_to_range(double old_min, \
		double old_max, double old_value);
void			draw_player(t_mlx mlx, t_map *map, t_data *data, int color);
t_dda			dda_struct(t_map *map, double angle);
int				is_player(char c);
void			init_map(t_map *map);
void			draw_minimap(t_map *map, t_mlx mlx, t_data *data);
int				is_wall(char c);
double			abs_num(double a);
void			rectangle_map(t_map *map);
void			signs_movement(double angle, int *signe_x, int *signe_y);
int				map_range(t_map map, double *xf, double *yf);
int				general_check(t_map *map, int dx, int *buttom, int *head);
char			**ft_strdup_tab(char **tab, int head, int buttom);
int				many_players_check(char c, int *cnt);
int				unknown_byte(char c);
int				empty_line(char c);
int				is_surrounded(char **map, int i, int j);
int				test_west(char **map, int i, int j);
int				test_east(char **map, int i, int j);
int				test_south(char **map, int i, int j);
int				test_north(char **map, int i, int j);
int				repeted_words_check(char **info, char *tab, int *cnt, int d);
int				words_checker(char **str, int *cnt, t_info *info);
int				f_part_checker(char **map, t_info *info);
int				spaces_line(char *line);
int				buttom_map_check(char **tmp, int dx, int *buttom);
void			free_tab(char **str);
int				ft_cmp(const char *s1, char *s2);
int				extension_checker(char *name);
int				numbers_checker(char *str, t_info *info, char c);
int				last_return(int *cnt, int d);
double			abs_double(double x);
int				is_between(double n, int min, int max);
int				is_player(char c);
void			init_textures_and_angle(t_map *map, t_info info);
void			check_tile_size(t_height_width a, t_height_width b,
					t_height_width c, t_height_width d);

#endif
