/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:56:27 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/08 14:01:30 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_point(t_data fdf_data, t_point *list_point, t_img img)
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
			draw_line(fdf_data, list_point, tmp, img);
		while (tmp && tmp->id != list_point->id + line_len)
			tmp = tmp->next;
		if (tmp)
			draw_line(fdf_data, list_point, tmp, img);
		list_point = list_point->next;
	}
	ft_memdel((void *)img.img_pixel);
}

void	h_pixel(t_coord p1, t_coord p2, t_coord inc, t_img img)
{
	int		i;
	int		cumul;
	int		calcul;

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
		calcul = (p2.y * img.len) + (p2.x * (img.bit_per_p / 8));
		img.img_pixel[calcul] = inc.color[0];
		img.img_pixel[calcul + 1] = inc.color[1];
		img.img_pixel[calcul + 2] = inc.color[2];
		i++;
	}
}

void	v_pixel(t_coord p1, t_coord p2, t_coord inc, t_img img)
{
	int		i;
	int		cumul;
	int		calcul;

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
		calcul = (p2.y * img.len) + (p2.x * (img.bit_per_p / 8));
		img.img_pixel[calcul] = inc.color[0];
		img.img_pixel[calcul + 1] = inc.color[1];
		img.img_pixel[calcul + 2] = inc.color[2];
		i++;
	}
}

void	draw_line(t_data fdf_data, t_point *point1, t_point *point2, t_img img)
{
	t_coord inc;
	t_coord p2;
	t_coord p1;
	int		calcul;

	init_color(&inc, point1, point2);
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
	calcul = (p2.y * img.len) + (p2.x * (img.bit_per_p / 8));
	img.img_pixel[calcul] = inc.color[0];
	img.img_pixel[calcul + 1] = inc.color[1];
	img.img_pixel[calcul + 2] = inc.color[2];
	if (p1.x > p1.y)
		h_pixel(p1, p2, inc, img);
	else
		v_pixel(p1, p2, inc, img);
}
