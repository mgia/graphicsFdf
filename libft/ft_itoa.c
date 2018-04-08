/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:40:55 by mtan              #+#    #+#             */
/*   Updated: 2018/03/12 17:09:18 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_len(long long int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long long int n)
{
	char	*ret;
	int		i;

	if ((unsigned long long)n == 9223372036854775808U)
		return (ft_strdup("-9223372036854775808"));
	if (n == -0)
		return (ft_strdup("0"));
	if (!(ret = ft_strnew(str_len(n))))
		return (NULL);
	i = str_len(n);
	if (n < 0)
	{
		n = -n;
		ret[0] = '-';
	}
	ret[i--] = 0;
	while (n > 0)
	{
		ret[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (ret);
}
