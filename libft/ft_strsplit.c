/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:18:08 by btollet           #+#    #+#             */
/*   Updated: 2016/11/18 13:02:04 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char		**result;
	int			i;
	int			start;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	if ((result = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))) == NULL)
		return (NULL);
	while (s[start] && s[start] == c)
		start++;
	while (ft_wordcount(s, c) - i > 0)
	{
		result[i] = ft_strsub(s, start, ft_wordlen(s, c, start));
		start += ft_wordlen(s, c, start);
		while (s[start] && s[start] == c)
			start++;
		i++;
	}
	result[i] = 0;
	return (result);
}
