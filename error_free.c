/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:04:53 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/02 13:05:10 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(char *mes, t_point *list_point)
{
	if (list_point)
		free_point(&list_point);
	ft_putendl(mes);
	exit(1);
}

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

t_point	*free_point(t_point **list_point)
{
	t_point	*save;

	while (*list_point)
	{
		save = (*list_point)->next;
		free(*list_point);
		*list_point = save;
	}
	*list_point = NULL;
	return(NULL);
}
