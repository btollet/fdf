/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:31:17 by btollet           #+#    #+#             */
/*   Updated: 2016/11/18 13:00:47 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = ft_intlen(n);
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(result, "-2147483648"));
	result[len] = '\0';
	if (n < 0)
	{
		result[i] = '-';
		n = -n;
	}
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (result);
}
