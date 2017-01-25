/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:45:13 by benjamin          #+#    #+#             */
/*   Updated: 2016/11/17 15:45:43 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t	result;
	t_list	*copy;

	result = 0;
	if (!lst)
		return (0);
	copy = lst;
	while (copy)
	{
		result++;
		copy = copy->next;
	}
	return (result);
}
