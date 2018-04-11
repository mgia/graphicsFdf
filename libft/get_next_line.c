/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:37:56 by mtan              #+#    #+#             */
/*   Updated: 2018/03/07 22:19:27 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_file(int fd, t_list **file)
{
	t_list			*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_list));
	tmp->content = malloc(1);
	ft_memcpy(tmp->content, "\0", 1);
	tmp->content_size = fd;
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

char			*linecpy(char *line, char *src, int i)
{
	int				j;

	j = 0;
	if (!(line = ft_strnew(i)))
		return (0);
	while (src[j] && j < i)
	{
		line[j] = src[j];
		j++;
	}
	return (line);
}

char			*ft_free(char **s1, int i)
{
	char	*tmp;

	tmp = ft_strdup(*s1 + i + 1);
	free(*s1);
	return (tmp);
}

char			*join(char **s1, char *s2)
{
	char	*str;
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = *s1;
	if (!tmp || !s2 || !(str = ft_strnew(ft_strlen(tmp) + ft_strlen(s2))))
		return (NULL);
	i = -1;
	j = -1;
	while (tmp[++i])
		str[i] = tmp[i];
	while (s2[++j])
		str[i++] = s2[j];
	free(*s1);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list;
	t_list			*file;
	int				i;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	file = get_file(fd, &list);
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		if (!(file->content = join((char**)&file->content, buf)))
			return (-1);
		if (ft_strchr(file->content, '\n'))
			break ;
	}
	if (i < BUFF_SIZE && !ft_strlen(file->content))
		return (0);
	i = ft_strchri(file->content, '\n');
	*line = linecpy(*line, file->content, i);
	if (i < (int)ft_strlen(file->content))
		file->content = ft_free((char**)&file->content, i);
	else
		ft_strclr(file->content);
	return (1);
}
