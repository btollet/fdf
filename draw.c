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

	y = pos[1] - 1;
	while (y++ < pos[2])
	{
		x = pos[0] - 1;
		while (x++ < pos[3])
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	}
}

/*void	draw_line(void *mlx, void *win, int *pos)
{
	int x;
	int y;
	int int_x;
	int i;
	int	j;
	int test;

	if (pos[2] - pos[0] > pos[3] - pos[1])
		int_x = (pos[2] - pos[0]) / (pos[3] - pos[1]);
	else
		int_x = (pos[3] - pos[1]) / (pos[2] - pos[0]);
	test = (((pos[3] - pos[1]) * 10) / (pos[2] - pos[0])) % 10;

	y = pos[1] - 1;
	x = pos[0];
	j = 0;
	while (y++ < pos[2])
	{
		i = 0;
		while (i++ < int_x + 1)
			mlx_pixel_put(mlx, win, x + i - 1, y, 0x00FF0000);
		if (j++ < test - 2 && test != 0)
			x++;
		if (j == 11)
			j = 0;
		x += int_x;
	}
}*/

void draw_line(void *mlx, void *win, int *pos) 
{
	int x1 = pos[0];
	int y1 = pos[1];
	int x2 = pos[2];
	int y2 = pos[3];

	int dx  = x2 - x1,
          dy  = y2 - y1,
          y = 0;

      for ( int x = x1; x <= x2; x++ )  
      {
      	y = y1 + dy * (x - x1) / dx;
        mlx_pixel_put(mlx, win, x, y, 0x00FF0000);

      }
}

