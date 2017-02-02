/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:56:27 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/02 12:12:47 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_point(t_data fdf_data, t_point *list_point)
{
	t_point	*save;
	t_point *tmp;
	int		line_len;

	line_len = list_point->line_len;
	save = list_point;
	while (list_point->next)
	{
		if (!list_point->id)
			list_point = list_point->next;
		tmp = list_point->next;
		if (tmp->x > list_point->x)
			draw_line(fdf_data, list_point, tmp);
		while (tmp && tmp->id != list_point->id + line_len)
			tmp = tmp->next;
		if (tmp)
			draw_line(fdf_data, list_point, tmp);
		list_point = list_point->next;
	}
}

void	h_pixel(t_data fdf_data, t_coord p1, t_coord p2, t_coord inc)
{
	int		i;
	int		cumul;

	i = 1;
	cumul = p1.x / 2;
	while (i <= p1.x)
	{
		p2.x += inc.x;
		cumul += p1.y;
		if (cumul >= p1.x)
		{
			cumul -= p1.x;
			p2.y += inc.y;
		}
		mlx_pixel_put(fdf_data.mlx, fdf_data.win, p2.x, p2.y, inc.color);
		i++;
	}
}

void	v_pixel(t_data fdf_data, t_coord p1, t_coord p2, t_coord inc)
{
	int		i;
	int		cumul;

	i = 1;
	cumul = p1.y / 2;
	while (i <= p1.y)
	{
		p2.y += inc.y;
		cumul += p1.x;
		if (cumul >= p1.y)
		{
			cumul -= p1.y;
			p2.x += inc.x;
		}
		mlx_pixel_put(fdf_data.mlx, fdf_data.win, p2.x, p2.y, inc.color);
		i++;
	}
}

void	draw_line(t_data fdf_data, t_point *point1, t_point *point2)
{
	t_coord inc;
	t_coord p2;
	t_coord p1;

	if (point1->color < point2->color)
		inc.color = point1->color;
	else
		inc.color = point2->color;
	p2.x = ((point1->x + fdf_data.decal_x) / fdf_data.div_x) * fdf_data.zoom;
	p2.y = ((point1->y + fdf_data.decal_y) / fdf_data.div_y) * fdf_data.zoom;
	p1.x = (((point2->x + fdf_data.decal_x) -
		(point1->x + fdf_data.decal_x)) / fdf_data.div_x) * fdf_data.zoom;
	p1.y = ((point2->y + fdf_data.decal_y) / fdf_data.div_y -
		(point1->y + fdf_data.decal_y) / fdf_data.div_y) * fdf_data.zoom;
	inc.x = (p1.x > 0) ? 1 : -1;
	inc.y = (p1.y > 0) ? 1 : -1;
	p1.x = abs(p1.x);
	p1.y = abs(p1.y);
	mlx_pixel_put(fdf_data.mlx, fdf_data.win, p2.x, p2.y, inc.color);
	if (p1.x > p1.y)
		h_pixel(fdf_data, p1, p2, inc);
	else
		v_pixel(fdf_data, p1, p2, inc);
}
