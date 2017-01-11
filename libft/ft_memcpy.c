/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:17:51 by btollet           #+#    #+#             */
/*   Updated: 2016/11/16 11:17:53 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	return (result);
}
