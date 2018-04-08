/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:40:55 by mtan              #+#    #+#             */
/*   Updated: 2018/02/21 17:41:09 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*tdest;
	unsigned char	*tsrc;
	size_t			i;

	tdest = (unsigned char*)str1;
	tsrc = (unsigned char*)str2;
	i = -1;
	if (tsrc < tdest)
		while (n--)
			tdest[n] = tsrc[n];
	else
		while (++i < n)
			tdest[i] = tsrc[i];
	return (str1);
}
