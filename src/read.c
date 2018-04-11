/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 22:12:28 by mtan              #+#    #+#             */
/*   Updated: 2018/04/10 22:12:31 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <limits.h>

int			clean(t_list **lst, t_map **map)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_memdel(&(*lst)->content);
		ft_memdel((void **)lst);
		*lst = next;
	}
	if (map && *map)
	{
		ft_memdel((void **)(*map)->vectors);
		ft_memdel((void **)map);
	}
	return (0);
}

void		fill_vector(t_map *map)
{
	t_vector	curr;
	int			y;
	int			x;

	map->depth_min = INT_MAX;
	map->depth_max = INT_MIN;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			curr = map->vectors[y * map->width + x];
			if (curr.z < map->depth_min)
				map->depth_min = curr.z;
			if (curr.z > map->depth_max)
				map->depth_max = curr.z;
			x++;
		}
		y++;
	}
}

t_vector	get_vector(int x, int y, char *str)
{
	t_vector v;

	v.x = (double)x;
	v.y = (double)y;
	v.z = (double)ft_atoi(str);
	v.color = 0xFFFFFF;
	return (v);
}

void		fill_map(t_map **map, t_list *src)
{
	t_list	*lst;
	char	**split;
	int		x;
	int		y;

	lst = src;
	y = -1;
	while (++y < (*map)->height)
	{
		x = -1;
		if (!(split = ft_strsplit(lst->content, ' ')))
		{
			clean(&src, map);
			return ;
		}
		while (++x < (*map)->width)
		{
			(*map)->vectors[y * (*map)->width + x] = get_vector(x, y, split[x]);
		}
		ft_strsplitdel(&split);
		lst = lst->next;
	}
	fill_vector(*map);
	clean(&src, NULL);
}

t_map		*get_map(t_list *lst)
{
	t_map	*map;

	if (!(map = ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->height = ft_lstcount(lst);
	map->width = ft_wordcount(lst->content, ' ');
	map->vectors = ft_memalloc(sizeof(t_vector) * map->height * map->width);
	if (!map->vectors)
	{
		ft_memdel((void **)&map);
		return (NULL);
	}
	return (map);
}
