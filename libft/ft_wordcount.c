/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:33:14 by benjamin          #+#    #+#             */
/*   Updated: 2016/11/17 15:36:49 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(const char *s, char c)
{
	int			result;
	int			i;

	i = 0;
	result = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i])
	{
		result++;
		while (s[i + 1])
		{
			if (s[i] == c && s[i + 1] != c)
				result++;
			i++;
		}
	}
	return (result);
}