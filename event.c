/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 11:31:57 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/02 13:09:33 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_data *fdf_data)
{
	if (key == 53)
	{
		free_point(&fdf_data->list_point);
		exit(1);
	}
	if (key == 124)
		change_window(fdf_data, 1);
	if (key == 123)
		change_window(fdf_data, 2);
	if (key == 24)
		zoom(fdf_data, 1);
	if (key == 27)
		zoom(fdf_data, 2);
	if (key == 0)
		move(fdf_data, 1);
	if (key == 2)
		move(fdf_data, 2);
	if (key == 1)
		move(fdf_data, 4);
	if (key == 13)
		move(fdf_data, 3);
	return (0);
}

void	change_window(t_data *fdf_data, int sens)
{
	if (sens == 1 && fdf_data->argv[fdf_data->actual_ar + 1])
	{
		mlx_destroy_window(fdf_data->mlx, fdf_data->win);
		fdf_data->zoom = 1;
		fdf_data->actual_ar++;
		free_point(&fdf_data->list_point);
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
	if (sens == 2 && fdf_data->actual_ar > 1)
	{
		mlx_destroy_window(fdf_data->mlx, fdf_data->win);
		fdf_data->zoom = 1;
		fdf_data->actual_ar--;
		free_point(&fdf_data->list_point);
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
}

void	zoom(t_data *fdf_data, int sens)
{
	if (sens == 1 && fdf_data->zoom == 1)
	{
		mlx_clear_window(fdf_data->mlx, fdf_data->win);
		fdf_data->zoom++;
		fdf_data->decal_x -= (fdf_data->win_x / 2) / fdf_data->zoom;
		fdf_data->decal_y -= (fdf_data->win_y / 2) / fdf_data->zoom;
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
	if (sens == 2 && fdf_data->zoom >= 2)
	{
		mlx_clear_window(fdf_data->mlx, fdf_data->win);
		fdf_data->decal_x += (fdf_data->win_x / 2) / fdf_data->zoom;
		fdf_data->decal_y += (fdf_data->win_y / 2) / fdf_data->zoom;
		fdf_data->zoom--;
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
}

void	move(t_data *fdf_data, int dir)
{
	if (dir == 1 || dir == 2)
	{
		if (dir == 1)
			fdf_data->decal_x -= 10;
		if (dir == 2)
			fdf_data->decal_x += 10;
	}
	if (dir == 3 || dir == 4)
	{
		if (dir == 3)
			fdf_data->decal_y -= 10;
		if (dir == 4)
			fdf_data->decal_y += 10;
	}
	mlx_clear_window(fdf_data->mlx, fdf_data->win);
	call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
}