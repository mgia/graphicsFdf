/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 21:28:08 by mtan              #+#    #+#             */
/*   Updated: 2018/05/08 21:28:09 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define BASE_COLOR 0x008080
#define PEAK_COLOR 0xffce00

int			shift(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

double		get_gradient(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

int			get_color(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = shift((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = shift((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = shift(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

void		fill_colors(t_map *m)
{
	t_vector	v;
	t_vector	*cur;

	v.y = 0;
	while (v.y < m->height)
	{
		v.x = 0;
		while (v.x < m->width)
		{
			cur = &m->vectors[(int)v.y * m->width + (int)v.x];
			cur->color = get_color(BASE_COLOR, PEAK_COLOR, get_gradient(cur->z,
				m->depth_min, m->depth_max));
			v.x++;
		}
		v.y++;
	}
}
