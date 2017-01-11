/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:56:27 by benjamin          #+#    #+#             */
/*   Updated: 2016/12/27 16:03:06 by benjamin         ###   ########.fr       */
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

void draw_line(void *mlx, void *win, int *pos) 
{
	int x1 = pos[0];
	int y1 = pos[1];
	int x2 = pos[2];
	int y2 = pos[3];

	int dx,dy,i,xinc,yinc,cumul,x,y ;
	x = x1 ;
	y = y1 ;
	dx = x2 - x1 ;
	dy = y2 - y1 ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
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
			mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
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
			mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
		}
	}
}