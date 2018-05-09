/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 22:12:28 by mtan              #+#    #+#             */
/*   Updated: 2018/04/10 22:12:31 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

t_vector	rotate(t_vector v, t_cam *cam)
{
	t_vector	res;
	double		x;
	double		y;
	double		z;

	x = v.x;
	z = v.z;
	res.x = sin(cam->y) * z + cos(cam->y) * x;
	res.z = cos(cam->y) * z - sin(cam->y) * x;
	y = v.y;
	z = res.z;
	res.y = cos(cam->x) * y - sin(cam->x) * z;
	res.z = sin(cam->x) * y + cos(cam->x) * z;
	res.color = v.color;
	return (res);
}

t_vector	vector_at(t_map *map, int x, int y)
{
	return (map->vectors[y * map->width + x]);
}

t_vector	project_vector(t_vector v, t_mlx *mlx)
{
	v.x -= (double)(mlx->map->width - 1) / 2.0;
	v.y -= (double)(mlx->map->height - 1) / 2.0;
	v.z -= (double)(mlx->map->depth_min + mlx->map->depth_max) / 2.0f;
	v = rotate(v, mlx->cam);
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offsetx;
	v.y += mlx->cam->offsety;
	return (v);
}

void		draw(t_mlx *mlx, t_vector p1, t_vector p2)
{
	t_line	line;
	double	steps;
	double	xinc;
	double	yinc;
	int		i;

	line.dy = (int)p2.y - (int)p1.y;
	line.dx = (int)p2.x - (int)p1.x;
	line.start = p1.x;
	line.end = p1.x + line.dx;
	if (ft_abs(line.dx) > ft_abs(line.dy))
		steps = ft_abs(line.dx);
	else
		steps = ft_abs(line.dy);
	xinc = line.dx / steps;
	yinc = line.dy / steps;
	i = -1;
	while (++i < steps)
	{
		p1.x += xinc;
		p1.y += yinc;
		set_pixel(mlx->image, (int)p1.x, (int)p1.y,
					get_color(p1.color, p2.color,
						get_gradient(p1.x, line.start, line.end)));
	}
}

void		render(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	v;
	t_map		*map;

	clear_image(mlx->image);
	map = mlx->map;
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			v = project_vector(vector_at(map, x, y), mlx);
			if (x + 1 < map->width)
				draw(mlx, v, project_vector(vector_at(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				draw(mlx, v, project_vector(vector_at(map, x, y + 1), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
