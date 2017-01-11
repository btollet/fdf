/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:50:15 by benjamin          #+#    #+#             */
/*   Updated: 2016/11/10 00:07:44 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void *result;

	result = (void *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (NULL);
	ft_memset(result, '\0', size + 1);
	return (result);
}
