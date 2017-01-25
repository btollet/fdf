/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:06:07 by btollet           #+#    #+#             */
/*   Updated: 2016/11/18 12:58:52 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		begin;
	int		end;
	char	*result;

	if (s)
	{
		begin = 0;
		while ((s[begin] == ' ' || s[begin] == '\n'
			|| s[begin] == '\t') && s[begin])
			begin++;
		end = ft_strlen(s) - 1;
		if (begin >= end)
		{
			result = (char *)malloc(sizeof(char) * 1);
			result[0] = '\0';
			return (result);
		}
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		result = (char *)malloc(sizeof(char) * (end - begin) + 1);
		return (result = ft_strsub(s, begin, end - begin + 1));
	}
	return (NULL);
}
