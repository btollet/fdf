/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:20:12 by btollet           #+#    #+#             */
/*   Updated: 2016/11/18 12:49:05 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*result;
	char	*copy;

	i = 0;
	result = dest;
	copy = (char *)src;
	while (i < n)
	{
		result[i] = copy[i];
		if (copy[i] == c)
			return (result + i + 1);
		i++;
	}	
	return (NULL);
}
