/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 22:12:28 by mtan              #+#    #+#             */
/*   Updated: 2018/04/10 22:12:31 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		error(char *str)
{
	ft_putendl(str);
	return (1);
}

void	init_cam(t_mlx *mlx)
{
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 30;
	mlx->cam->offsetx = WINDOW_W / 2;
	mlx->cam->offsety = WINDOW_H / 2;
}

int		hook_keyboard(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 125)
	{
		mlx->cam->scale -= (mlx->cam->scale * 50 / 100);
		render(mlx);
	}
	else if (key == 126)
	{
		if (mlx->cam->scale == 1)
			mlx->cam->scale++;
		mlx->cam->scale += (mlx->cam->scale * 50 / 100);
		render(mlx);
	}
	return (0);
}

t_mlx	*delete_mlx(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	if (mlx->image != NULL)
		delete_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init_mlx(char *title)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()) ||
		!(mlx->window = mlx_new_window(mlx->mlx, WINDOW_W,
		WINDOW_H, title)) ||
		!(mlx->cam = ft_memalloc(sizeof(t_cam))) ||
		!(mlx->image = create_image(mlx)))
		return (delete_mlx(mlx));
	ft_strdel(&title);
	init_cam(mlx);
	return (mlx);
}
