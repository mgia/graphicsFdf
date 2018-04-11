/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 22:12:28 by mtan              #+#    #+#             */
/*   Updated: 2018/04/10 22:12:31 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

void	set_pixel(t_image *img, int x, int y, int color)
{
	if (x < 0 || x >= WINDOW_W || y < 0 || y >= WINDOW_H)
		return ;
	*(int *)(img->ptr + ((y * WINDOW_W + x) * img->bpp)) = color;
}

void	clear_image(t_image *image)
{
	ft_bzero(image->ptr, WINDOW_H * WINDOW_W * image->bpp);
}

t_image	*delete_image(t_mlx *mlx, t_image *img)
{
	if (img)
	{
		if (img->image)
			mlx_destroy_image(mlx->mlx, img->image);
		ft_memdel((void **)&mlx);
	}
	return (NULL);
}

t_image	*create_image(t_mlx *mlx)
{
	t_image		*img;

	if (!(img = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(img->image = mlx_new_image(mlx->mlx, WINDOW_W, WINDOW_H)))
		return (delete_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
				&img->endian);
	img->bpp /= 8;
	return (img);
}
