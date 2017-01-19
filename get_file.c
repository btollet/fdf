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
	y = 1;
	list_point = add_point(0, 0, 0, 0);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if ((list_point = split_to_list(list_point, ft_strsplit(line, ' ')
			, y++)) == NULL)
			return (NULL);
	}
	close(fd);
	if (list_point->id == 0)
		list_point->line_count = y - 1;
	if (ret == -1)
		return (NULL);
	return (list_point);
}

t_point	*add_point(int id, int x, int y, int z)
{
	t_point *new_point;

	if ((new_point = (t_point *)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	new_point->id = id;
	new_point->x = x;
	new_point->y = (y - z);
	new_point->z = z;
	new_point->line_len = 0;
	new_point->line_count = 0;
	new_point->win_x = 0;
	new_point->win_y = 0;
	new_point->decal = 0;
	new_point->next = NULL;
	return (new_point);
}

t_point	*split_to_list(t_point *list_point, char **split, int y)
{
	int		id;
	int		x;
	int		i;
	t_point *result;

	i = 0;
	x = 1;
	result = list_point;
	while (list_point->next)
		list_point = list_point->next;
	id = list_point->id + 1;
	while (split[i])
	{
		if ((list_point->next = add_point(id, x * 20 + y * 10, y * 15
			, (ft_atoi(split[i]) * HEIGHT))) == NULL)
			return (NULL);
		list_point = list_point->next;
		result = check_win(result, list_point);
		id++;
		x++;
		i++;
	}
	result->line_len = i;
	return (result);
}

t_point	*check_win(t_point *result, t_point *point)
{
	int	y;

	y = point->y + result->decal;
	while (y < 10)
	{
		result->win_y += 10;
		result->decal += 10;
		y += 10;
	}
	while (point->x > result->win_x + 20)
		result->win_x += 10;
	while (point->y > result->win_y - result->decal + 20)
		result->win_y += 10;
	return (result);
}
