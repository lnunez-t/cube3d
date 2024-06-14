/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:21:21 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/11 12:49:09 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../srcs/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* MAP SETTINGS */

# define WIN_WIDTH 6100000
# define WIN_HEIGHT 500000
/* # define WIN_WIDTH 1920
# define WIN_HEIGHT 1080 */
# define WIN_TITLE "CUBE 3D"

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

# define TEX_SIZE 32

# define MOVESPEED 0.099999999999999
//# define MOVESPEED 0.125
# define ROTSPEED 0.015

/* ERROR MESSAGES */

# define ERR_PATH "Invalid path"
# define ERR_ARGS "Invalid arguments"
# define ERR_INFO_MAP "Information missing in the map"
# define ERR_OPEN_FILE "File could not be opened"
# define ERR_MAP "Invalid map, there is a"
# define ERR_WALL "Map is not surrounded by walls"
# define ERR_MALLOC "Malloc error"
# define ERR_MLX_PTR "Couldn't find mlx_ptr"
# define ERR_WIN "Couldn't create the window"

/* STRUCTURES DEFINITIONS */

enum				e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_pos
{
	int				x;
	int				y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	struct s_pos	*next;
}					t_pos;

typedef struct s_img
{
	void			*xpm_img;
	int				*addr;
	int				pixel_bits;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_map
{
	char			**all;
	int				rows;
	int				cols;
	int				index_map;
	char			*path;
}					t_map;

typedef struct s_name
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				*ceiling;
	int				*floor;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				x;
	int				y;
	int				size;
	int				index;
	double			step;
	double			pos;
	char			**maps;
}					t_name;

typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			wall_dist;
	double			wall_x;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_player
{
	char			dir;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
}					t_player;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_height;
	int				win_width;
	t_map			map_info;
	t_player		player;
	t_ray			ray;
	int				**texture_pixels;
	int				**textures;
	t_name			tex;
	t_img			map;
}					t_data;

/* PARSING */

int					verif_path_cub(char *name);
int					verif_path(char *name);
void				ft_parse_first(char *line, int *i, t_data *data, int fd);
int					parsing(char *str, t_data *data);
int					ft_open(char *name, t_data *data);
void				ft_parse(int fd, t_data *data);
void				ft_parse_map(char *line, t_data *data, int *k);
int					ft_size_maps(t_data *data);
int					ft_verif_maps(t_data *data, int fd);
int					ft_verif_maps_chemin(char **maps, int i);
void				ft_replace_carac(char **map);
char				*ft_replace_line(char *src, int end);
char				*ft_first_line(char **maps);
int					ft_verif_maps_carac(char **maps);
int					ft_strlen_max(char **map);
int					ft_max_line(char **map);
int					ft_verif_main(char **map);
int					ft_verif_first(char **map);
int					ft_verif_mid(char **map, int k);
int					ft_verif_last(char **map, int k);
int					ft_verif_maps_playeur(char **map);
char				*eeee(char *str);

/* INIT  */

void				init_data(t_data *data);
int					count_rows(t_data *data);
void				init_mlx(t_data *data);
void				init_img_clean(t_img *img);
void				init_img(t_data *data, t_img *image, int width, int height);
void				init_texture_img(t_data *data, t_img *image, char *path);
void				init_texinfo(t_name *textures);
void				init_ray(t_ray *ray);
void				init_player(t_player *player);
void				ft_init_name(t_data *data);
void				init_textures(t_data *data);
void				init_sprites(t_data *data);
void				update_textures(t_data *data, t_name *tex, t_ray *ray,
						int x);
void				set_image_pixel(t_img *image, int x, int y, int color);
void				destroy_sprites(t_data *data);
void				free_map(t_data *data);
int					close_window(t_data *data);
long long			millitimestamp(void);
void				print_map(t_data *data);
void				init_dir(t_data *data);
int					*get_rgb(char *line);
int					*convert_rgb(char **char_rgb, int *rgb);
int					check_textures(t_name *tex);
unsigned long		convert_hex(int *rgb);
int					valid_rgb(int *rgb);

/* PLAYER */

void				find_player(t_data *data);
int					player_move(t_data *data);
int					move_up(t_data *data);
int					move_down(t_data *data);
int					move_left(t_data *data);
int					move_right(t_data *data);
int					rotate_player(t_data *data, double rotate);
int					valid_move(t_data *data, double new_posx, double new_posy);
int					camera_move(t_data *data, double rotspeed);
void				handle_input(t_data *data);
int					handle_keysym(int keysym, t_data *data);
int					release_keysym(int keysym, t_data *data);

/* RAYCAST */

int					raycaster(t_player *player, t_data *data);

/* RENDER MAP */

int					render(t_data *data);
void				render_map(t_data *data);

/* END */

int					close_window(t_data *data);
void				ft_end(t_data *data, int exit_code);
void				ft_free_all(t_data *data);
void				free_textures(t_name *tex);

#endif
