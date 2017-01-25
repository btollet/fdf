/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:16:59 by benjamin          #+#    #+#             */
/*   Updated: 2016/11/18 12:43:49 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *next;

	if (!lst)
		return (NULL);
	result = f(lst);
	next = result;
	while (lst->next)
	{
		result->next = f(lst->next);
		result = result->next;
		lst = lst->next;
	}
	return (next);
}
