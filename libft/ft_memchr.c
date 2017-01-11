/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:21:06 by btollet           #+#    #+#             */
/*   Updated: 2016/11/18 12:47:02 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)s;
	while (i < n && result[i] != (char)c)
		i++;
	if (i < n && result[i] == (char)c)
		return (&result[i]);
	return (NULL);
}
