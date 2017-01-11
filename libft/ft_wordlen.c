/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:33:35 by benjamin          #+#    #+#             */
/*   Updated: 2016/11/17 15:38:11 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(const char *s, char c, int start)
{
	int			len;

	len = 0;
	while (s[start] && s[start] == c)
		start++;
	if (s[start])
	{
		while (s[start] != c && s[start])
		{
			start++;
			len++;
		}
	}
	return (len);
}