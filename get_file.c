/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 01:40:34 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/17 12:12:34 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*read_file(char *file)
{
	int		fd;
	int		ret;
	int		y;
	char	*line;
	t_point	*list_point;

	fd = open(file, O_RDONLY);
	y = 50;
	list_point = add_point(0, 0, 0, 0);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (NULL);
		if (ret == 0)
			break;
		list_point = split_to_list(list_point, ft_strsplit(line, ' '), y);
		y += DIST;
	}
	return (list_point);
}

t_point *add_point(int ID, int x, int y, int z)
{
	t_point *new_point;

	if ((new_point = (t_point *)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	new_point->ID = ID;
	new_point->x = x;
	new_point->y = y;
	new_point->z = z;
	new_point->next = NULL;
	return (new_point);
}

t_point	*split_to_list(t_point *list_point, char **split, int y)
{
	int		ID;
	int		x;
	int		i;
	t_point *result;

	i = 0;
	x = 50;
	result = list_point;
	while (list_point->next)
		list_point = list_point->next;
	ID = list_point->ID + 1;
	while (split[i])
	{
		list_point->next = add_point(ID, x, y, ft_atoi(split[i]));
		list_point = list_point->next;
		ID++;
		x += DIST;
		y += DIST / 4;
		i++;
	}
	return (result);
}