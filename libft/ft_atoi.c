/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:40:54 by mtan              #+#    #+#             */
/*   Updated: 2018/02/21 17:41:09 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		n;
	int		i;
	int		sign;
	int		count;

	n = 0;
	i = 0;
	sign = 1;
	count = 1;
	while (ft_iswspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? (-1) : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && count++)
		n = (n * 10) + (str[i++] - '0');
	return (n * sign);
}
