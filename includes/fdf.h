#ifndef FDF_H
# define FDF_H

# define WINDOW_H	700
# define WINDOW_W	1000

# include "libft.h"

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vector;

typedef struct	s_map
{
	int			height;
	int			width;
	int			depth_min;
	int			depth_max;
	t_vector	*vectors;
}				t_map;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef struct	s_cam
{
	int			scale;
	double		x;
	double		y;
	double		offsetx;
	double		offsety;
}				t_cam;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_image		*image;
	t_cam		*cam;
}				t_mlx;

typedef struct	s_line
{
	int			dy;
	int			dx;
}				t_line;

/*
**	Read functions
*/

int			read_file(int fd, t_map	**map);
int			get_lines(int fd, t_list **lst);
t_map		*get_map(t_list *lst);
void		fill_map(t_map **map, t_list *src);
t_vector	get_vector(int x, int y, char *str);
void		fill_vector(t_map *map);
int			clean(t_list **lst, t_map **map);

/*
** Image functions
*/

void	set_pixel(t_image *img, int x, int y, int color);
t_image	*delete_image(t_mlx *mlx, t_image *img);
t_image *create_image(t_mlx *mlx);
void	clear_image(t_image *image);

/*
** Draw functions
*/

t_vector	rotate(t_vector v, t_cam *cam);
t_vector	vector_at(t_map *map, int x, int y);
t_vector	project_vector(t_vector v, t_mlx *mlx);
void		render(t_mlx *mlx);

/*
** Helper functions
*/

int		error(char *str);
void	init_cam(t_mlx *mlx);
t_mlx	*delete_mlx(t_mlx *mlx);
t_mlx	*init_mlx(char *title);
int		hook_keyboard(int key, t_mlx *mlx);

#endif
