/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:38:02 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/29 14:29:39 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	check_win(t_point *list_point, t_data fdf_data)
{
	int		xy;

	while (list_point)
	{
		xy = list_point->x + fdf_data.decal_x;
		while (xy < 10)
		{
			fdf_data.win_x += 10;
			fdf_data.decal_x += 10;
			xy += 10;
		}
		xy = list_point->y + fdf_data.decal_y;
		while (xy < 10)
		{
			fdf_data.win_y += 10;
			fdf_data.decal_y += 10;
			xy += 10;
		}
		while (list_point->x > fdf_data.win_x - fdf_data.decal_x - 20)
			fdf_data.win_x += 10;
		while (list_point->y > fdf_data.win_y - fdf_data.decal_y - 20)
			fdf_data.win_y += 10;
		list_point = list_point->next;
	}
	return (fdf_data);
}

t_data		fdf_init(t_point *list_point, t_data fdf_data)
{
	int		copy;

	fdf_data.win_x = 10;
	fdf_data.win_y = 10;
	fdf_data.decal_y = 0;
	fdf_data.decal_x = 0;
	fdf_data = check_win(list_point, fdf_data);
	fdf_data.mlx = mlx_init();
	copy = fdf_data.win_x;
	fdf_data.div_x = 1;
	while (copy >= 1500)
	{
		fdf_data.div_x ++;
		copy -= 1500;
	}
	copy = fdf_data.win_y;
	fdf_data.div_y = 1;
	while (copy >= 1000)
	{
		fdf_data.div_y ++;
		copy -= 1000;
	}
	fdf_data.win = mlx_new_window(fdf_data.mlx, fdf_data.win_x / fdf_data.div_x
		, fdf_data.win_y / fdf_data.div_y, "botllet fdf");
	return (fdf_data);
}