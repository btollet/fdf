/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:03:20 by btollet           #+#    #+#             */
/*   Updated: 2016/11/07 17:06:48 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *src, const char *comp)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = NULL;
	if (!comp[i])
		result = (char *)&src[0];
	while (src[i] && comp[j])
	{
		while (src[i + j] == comp[j] && src[i + j] && comp[j])
		{
			result = (char *)&src[i];
			j++;
		}
		if (comp[j])
		{
			result = NULL;
			j = 0;
		}
		i++;
	}
	return (result);
}
