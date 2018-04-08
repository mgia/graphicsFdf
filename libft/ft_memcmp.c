/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:40:55 by mtan              #+#    #+#             */
/*   Updated: 2018/02/21 17:41:09 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char	*tstr1;
	unsigned const char	*tstr2;
	size_t				i;

	tstr1 = (unsigned char*)str1;
	tstr2 = (unsigned char*)str2;
	i = -1;
	while (++i < n)
	{
		if (tstr1[i] != tstr2[i])
			return (tstr1[i] - tstr2[i]);
	}
	return (0);
}
