/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 22:12:28 by mtan              #+#    #+#             */
/*   Updated: 2018/04/10 22:12:31 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>

int		get_lines(int fd, t_list **lst)
{
	char	*line;
	t_list	*node;
	int		count;
	int		i;

	count = -1;
	while ((i = get_next_line(fd, &line)))
	{
		if (count == -1)
			count = ft_wordcount(line, ' ');
		else if (count != ft_wordcount(line, ' '))
			return (clean(lst, NULL));
		if (!(node = ft_lstnew(line, ft_strlen(line) + 1)))
			return (clean(lst, NULL));
		ft_lstaddback(lst, node);
		ft_strdel(&line);
	}
	if (count == -1 || i == -1)
		return (0);
	return (1);
}

int		read_file(int fd, t_map **map)
{
	t_list	*lst;

	lst = NULL;
	if (!get_lines(fd, &lst))
		return (0);
	if (!(*map = get_map(lst)))
		return (clean(&lst, NULL));
	fill_map(map, lst);
	return (1);
}

int		main(int ac, char **av)
{
	t_map	*map;
	t_mlx	*mlx;
	int		fd;

	if (ac != 2)
		return (error("Usage: ./fdf [file name]"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !read_file(fd, &map))
		return (error("Error: Invalid File"));
	if (!(mlx = init_mlx(ft_strjoin("fdf -", av[1]))))
		return (error("Error: Could not initialize mlx"));
	mlx->map = map;
	render(mlx);
	mlx_key_hook(mlx->window, hook_keyboard, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
