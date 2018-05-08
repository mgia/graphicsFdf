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
#include "stdio.h"

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

t_mlx	*delete_mlx(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	if (mlx->image != NULL)
		delete_image(mlx, mlx->image);
	if (mlx->mouse != NULL)
		ft_memdel((void **)&mlx->mouse);
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
		!(mlx->mouse = ft_memalloc(sizeof(t_mouse))) ||
		!(mlx->image = create_image(mlx)))
		return (delete_mlx(mlx));
	ft_strdel(&title);
	init_cam(mlx);
	return (mlx);
}

void	display_help(void)
{
	printf("\n\t\t\tFDF: Actions\t\t\t\n");
	printf("---------------------------------------------------------\n");
	printf("|\tmouse => rotate\t\t\t\t\t|\n");
	printf("|\tkeyboard up => zoom in\t\t\t\t|\n");
	printf("|\tkeyboard down => zoom out\t\t\t|\n");
	printf("---------------------------------------------------------\n");
	printf("\t\t\tCreated by mtan\t\t\t\n");
}
