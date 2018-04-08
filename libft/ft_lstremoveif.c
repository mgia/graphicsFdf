/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:09:05 by mtan              #+#    #+#             */
/*   Updated: 2018/03/12 17:09:23 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Checks if content_size == i, and removes the node.
*/

void				ft_lstremoveif(t_list **alst, int i)
{
	t_list	*curr;
	t_list	*prev;

	curr = *alst;
	if ((int)curr->content_size == i)
	{
		*alst = (*alst)->next;
		free(curr->content);
		free(curr);
		return ;
	}
	while (curr)
	{
		prev = curr;
		if ((int)curr->content_size == i)
		{
			prev->next = curr->next;
			free(curr->content);
			free(curr);
			return ;
		}
		curr = curr->next;
	}
}
