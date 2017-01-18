/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:56:27 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/17 14:12:52 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_square(void *mlx, void *win, int *pos)
{
	int x;
	int y;

	x = pos[1] - 1;
	while (x++ < pos[2])
	{
		y = pos[0] - 1;
		while (y++ < pos[3])
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	}
}

/*void draw_line(t_data *fdf_data, t_point *point1, t_point *point2)
{
	int x1 = point1->x;
	int y1 = point1->y - point1->z * HEIGHT;
	int x2 = point2->x;
	int y2 = point2->y - point2->z * HEIGHT;

	int dx,dy,i,xinc,yinc,cumul,x,y ;
	int color = 0x00FFFFFF;
	if (point1->z > 0 && point2->z > 10)
		 color = 0x00FF3300;
	if ((point1->z == 0 && point2->z > 0) || (point1->z > 0 && point2->z == 0))
		 color = 0x00FF9933;
	if ((point1->z == 0 && point2->z < 0) || (point1->z < 0 && point2->z == 0))
		 color = 0x0000CCFF;
	if (point1->z < 0 && point2->z < 10)
		 color = 0x000033FF;

}*/

void	h_pixel(t_data *fdf_data, t_coord p1, t_coord p2, t_coord inc)
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
			cumul += p1.x;
			p2.y += inc.y;
		}
		mlx_pixel_put(fdf_data->mlx, fdf_data->win, p2.x, p2.y, inc.color);
		i++;
	}
}

void	v_pixel(t_data *fdf_data, t_coord p1, t_coord p2, t_coord inc)
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
		mlx_pixel_put(fdf_data->mlx, fdf_data->win, p2.x, p2.y, inc.color);
		i++;
	}
}

void	draw_line(t_data *fdf_data, t_point *point1, t_point *point2)
{
	t_coord inc;
	t_coord p2;
	t_coord p1;

	inc.color = 0x00FFFFFF;
	if (point1->z > 0 && point2->z > 10)
		 inc.color = 0x00FF3300;
	if ((point1->z == 0 && point2->z > 0) || (point1->z > 0 && point2->z == 0))
		 inc.color = 0x00FF9933;
	if ((point1->z == 0 && point2->z < 0) || (point1->z < 0 && point2->z == 0))
		 inc.color = 0x0000CCFF;
	if (point1->z < 0 && point2->z < 10)
		 inc.color = 0x000033FF;

	p2.x = point1->x;
	p2.y = point1->y - point1->z * HEIGHT;
	p1.x = point2->x - point1->x;
	p1.y = (point2->y - point2->z * HEIGHT) - (point1->y - point1->z * HEIGHT);
	inc.x = (p1.x > 0) ? 1 : -1;
	inc.y = (p1.y > 0) ? 1 : -1;
	p1.x = abs(p1.x);
	p1.y = abs(p1.y);
	mlx_pixel_put(fdf_data->mlx, fdf_data->win, p2.x, p2.y, inc.color);
	if (p1.x > p1.y)
		h_pixel(fdf_data, p1, p2, inc);
	else
		v_pixel(fdf_data, p1, p2, inc);
}
