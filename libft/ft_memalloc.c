/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:53:49 by benjamin          #+#    #+#             */
/*   Updated: 2016/11/10 09:39:03 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *result;

	result = (char *)malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, size);
	return (result);
}
