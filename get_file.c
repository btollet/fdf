/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 01:40:34 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/31 14:57:18 by benjamin         ###   ########.fr       */
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
	list_point = add_point(0, 0, 0, NULL);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if ((list_point = split_to_list(list_point, ft_strsplit(line, ' ')
			, y++)) == NULL)
			return (free_point(&list_point));
	}
	close(fd);
	if (list_point->id == 0)
		list_point->line_count = y - 1;
	if (ret == -1)
		return (free_point(&list_point));
	return (list_point);
}

t_point	*add_point(int id, int x, int y, char *split)
{
	int		z;
	int		color;
	t_point *new_point;

	z = 0;
	color = 0x00FFFFFF;
	if (split)
	{
		z = ft_atoi(split) * HEIGHT;
		color = get_color(split);
	}
	if ((new_point = (t_point *)malloc(sizeof(t_point))) == NULL)
		error("Malloc error");
	new_point->id = id;
	new_point->x = x;
	new_point->y = (y - z);
	new_point->line_len = 0;
	new_point->line_count = 0;
	new_point->color = color;
	new_point->next = NULL;
	return (new_point);
}

int		get_color(char *split)
{
	char	*c;
	int		i;
	int		rc;
	int		result;

	result = 16777215;
	if ((c = ft_strchr(split, ',')))
	{
		split = c + 1;
		result = 0;
		rc = 0;
		i = ft_strlen(split);
		while (--i > 0 && split[i] != 'x')
		{
			if (split[i] >= 'a' && split[i] <= 'f')
				result += (split[i] - 'a' + 10) * (int)pow(16, rc);
			if (split[i] >= 'A' && split[i] <= 'F')
				result += (split[i] - 'A' + 10) * (int)pow(16, rc);
			if (split[i] >= '1' && split[i] <= '9')
				result += (split[i] - '0') * (int)pow(16, rc);
			rc++;
		}
	}
	return (result);
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
		list_point->next = add_point(id, (y - x) * 20 / 2, (y + x) * 20 / 2
			, (split[i]));
		list_point = list_point->next;
		id++;
		x--;
		i++;
	}
	free_split(split);
	if (result->line_len != 0 && i != result->line_len)
		error_free("Found wrong line length. Exiting.", result);
	result->line_len = i;
	return (result);
}
