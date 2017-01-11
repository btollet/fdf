/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:34:45 by btollet           #+#    #+#             */
/*   Updated: 2016/11/08 17:34:48 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *comp, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	result = NULL;
	if (!comp[i])
		result = (char *)&src[0];
	while (src[i] && comp[j] && i < len)
	{
		while (src[i + j] == comp[j] && src[i + j] && comp[j] && i + j < len)
		{
			result = (char *)&src[i];
			j++;
		}
		if (src[i] && comp[j])
		{
			result = NULL;
			j = 0;
		}
		i++;
	}
	return (result);
}
