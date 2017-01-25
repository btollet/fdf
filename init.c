/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:38:02 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/24 15:40:07 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	check_win(t_point *list_point)
{
	int		y;
	t_data	fdf_data;

	fdf_data.win_x = 10;
	fdf_data.win_y = 10;
	fdf_data.decal = 0;
	while (list_point)
	{
		y = list_point->y + fdf_data.decal;
		while (y < 10)
		{
			fdf_data.win_y += 10;
			fdf_data.decal += 10;
			y += 10;
		}
		while (list_point->x > fdf_data.win_x - 20)
			fdf_data.win_x += 10;
		while (list_point->y > fdf_data.win_y - fdf_data.decal - 20)
			fdf_data.win_y += 10;
		list_point = list_point->next;
	}
	return (fdf_data);
}

t_data		fdf_init(t_point *list_point)
{
	int		div;
	int		x_copy;
	int		y_copy;
	t_data	fdf_data;

	div = 1;
	fdf_data = check_win(list_point);
	fdf_data.mlx = mlx_init();
	x_copy = fdf_data.win_x;
	y_copy = fdf_data.win_y;
	while (x_copy >= 1000 || y_copy >= 1000)
	{
		div ++;
		x_copy -= 1000;
		y_copy -= 1000;
	}
	fdf_data.win = mlx_new_window(fdf_data.mlx, fdf_data.win_x / div, fdf_data.win_y / div, "botllet fdf");
	fdf_data.div = div;
	return (fdf_data);
}