/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:41:02 by mtan              #+#    #+#             */
/*   Updated: 2018/02/21 17:41:10 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	j = ft_strlen(&s[i]) - 1;
	while (s[i] && (s[j + i] == ' ' || s[j + i] == '\t' || s[j + i] == '\n'))
		j--;
	if (!(str = ft_strsub(s, i, j + 1)))
		return (NULL);
	return (str);
}
