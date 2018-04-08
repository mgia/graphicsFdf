/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:41:00 by mtan              #+#    #+#             */
/*   Updated: 2018/02/21 17:41:09 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strjoin is modified to free the address pointed by param s2.
*/

char	*ft_strjoin(char const *s1, char **s2)
{
	char	*str;
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = *s2;
	if (!s1 || !tmp || !(str = ft_strnew(ft_strlen(s1) + ft_strlen(tmp))))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (tmp[++j])
		str[i++] = tmp[j];
	free(tmp);
	return (str);
}
