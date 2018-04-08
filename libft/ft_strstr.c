/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:41:02 by mtan              #+#    #+#             */
/*   Updated: 2018/02/21 17:41:10 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	if (!needle[0])
		return ((char *)&haystack[i]);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
