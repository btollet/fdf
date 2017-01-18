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

void draw_line(void *mlx, void *win, t_point *point1, t_point *point2) 
{
	int x1 = point1->x - point1->z * HEIGHT / 4;
	int y1 = point1->y - point1->z * HEIGHT;
	int x2 = point2->x - point2->z * HEIGHT / 4;
	int y2 = point2->y - point2->z * HEIGHT;

	int dx,dy,i,xinc,yinc,cumul,x,y ;
	int color = 0x00FFFFFF;
	if (point1->z == 10 && point2->z == 10)
		 color = 0x00FF3300;
	if ((point1->z == 0 && point2->z == 10) || (point1->z == 10 && point2->z == 0))
		 color = 0x00FF9933;

	
	x = x1 ;
	y = y1 ;
	dx = x2 - x1 ;
	dy = y2 - y1 ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	mlx_pixel_put(mlx, win, x, y, color);
	if ( dx > dy )
	{
		cumul = dx / 2 ;
		for ( i = 1 ; i <= dx ; i++ )
		{
			x += xinc ;
			cumul += dy ;
			if ( cumul >= dx )
			{
				cumul -= dx ;
				y += yinc ;
			}
			mlx_pixel_put(mlx, win, x, y, color);
		}
	}
	else
	{
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ )
		{
			y += yinc;
			cumul += dx ;
			if ( cumul >= dy )
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(mlx, win, x, y, color);
		}
	}
}