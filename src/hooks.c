/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:50:23 by mtan              #+#    #+#             */
/*   Updated: 2018/05/08 16:50:24 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	bind_hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx->window, hook_keyboard, mlx);
	mlx_hook(mlx->window, 4, 0, hook_mouse_down, mlx);
	mlx_hook(mlx->window, 5, 0, hook_mouse_up, mlx);
	mlx_hook(mlx->window, 6, 0, hook_mouse_move, mlx);
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

int		hook_mouse_down(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->isdown |= 1 << button;
	return (0);
}

int		hook_mouse_up(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int		hook_mouse_move(int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	mlx->mouse->lastx = mlx->mouse->x;
	mlx->mouse->lasty = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isdown & (1 << 1))
	{
		mlx->cam->x += (mlx->mouse->lasty - y) / 200.0f;
		mlx->cam->y -= (mlx->mouse->lastx - x) / 200.0f;
	}
	else if (mlx->mouse->isdown & (1 << 2))
	{
		mlx->cam->scale += (mlx->mouse->lasty - y) / 10.0f + 0.5f;
		if (mlx->cam->scale < 1)
			mlx->cam->scale = 1;
	}
	if (mlx->mouse->isdown)
		render(mlx);
	return (0);
}
