/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:45:00 by mtan              #+#    #+#             */
/*   Updated: 2018/02/22 11:45:03 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	map = f(lst);
	head = map;
	lst = lst->next;
	while (lst)
	{
		map->next = f(lst);
		map = map->next;
		lst = lst->next;
	}
	return (head);
}
