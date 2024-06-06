/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:21:21 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/06/06 12:56:38 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define WIN_TITLE "CUBE 3D"

# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define UP 1
# define LEFT 2
# define RIGHT 3
# define DOWN 4

# define W '1'
# define F '0'

# define KEY_Q 113
# define KEY_ESC 65307

# define RED_PIXEL "\033[1;31m"
# define GREEN_PIXEL "\033[0;32m"

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
	int				x;
	int				y;
}					t_img;

typedef struct s_map
{
	char			all[8][25];
	int				rows;
	int				cols;
	t_pos			player;
}					t_map;

typedef struct s_name
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**f;
	char	**c;
	char	**maps;
}				t_name;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_name			name;
	t_map			map;
	t_img			wall;
	t_img			floor;
	t_img			sky;
}					t_data;

void				init_map(t_data *data);
char				*check_empty_line(char *map, t_data *data);
int					count_rows(t_data *data);
int					handle_input(int keysym, t_data *data);
void				raycaster(t_data *data);
void				which_sprite(t_data *data, int y, int x);
void				render_sprite(t_data *data, t_img sprite, int y, int x);
void				render_window(t_data *data);
void				ft_free(t_data *data);
void				destroy_sprites(t_data *data);
void				free_map(t_data *data);
int					close_window(t_data *data);
long long			millitimestamp(void);

// partie parsing

int	ft_open(char *name, t_data *data);
int	ft_size_maps(t_data *data);

// ft_init.c

void	ft_init_name(t_data *data);

// ft_end.c

void	ft_end(t_data *data);

// ft_verif_maps.c

int	ft_verif_maps(t_data *data);

// ft_verif_maps2.c

int	ft_verif_main(char **map);
int	ft_verif_first(char **map);
int	ft_verif_mid(char **map, int k);
int	ft_verif_last(char **map, int k);

#endif
