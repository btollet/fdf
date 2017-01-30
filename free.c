/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:09:10 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/26 14:48:17 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		ft_memdel((void *)&split[i]);
		i++;
	}
	ft_memdel((void **)split);
}

void	free_point(t_point **list_point)
{
	t_point	*save;

	while (*list_point)
	{
		save = (*list_point)->next;
		free(*list_point);
		*list_point = save;
	}
	*list_point = NULL;
}
