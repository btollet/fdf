/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:47:05 by btollet           #+#    #+#             */
/*   Updated: 2016/11/16 11:47:06 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *result;

	if ((result = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		result->content = NULL;
		result->content_size = 0;
	}
	else
	{
		if ((result->content = malloc(content_size)) == NULL)
		{
			free(result);
			return (NULL);
		}
		ft_memcpy(result->content, (void *)content, content_size);
		result->content_size = content_size;
	}
	result->next = NULL;
	return (result);
}
