/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 11:31:57 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/04 16:59:08 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_data *fdf_data)
{
	if (key == 53)
	{
		free_point(&fdf_data->list_point);
		mlx_destroy_image(fdf_data->mlx, fdf_data->img);
		mlx_destroy_window(fdf_data->mlx, fdf_data->win);
		exit(1);
	}
	if (key == 124)
		change_window(fdf_data, 1);
	if (key == 123)
		change_window(fdf_data, 2);
	if (key == 24 || key == 27)
		zoom(fdf_data, key);
	if (key == 0 || key == 2 || key == 1 || key == 13 || key == 8)
		move(fdf_data, key);
	return (0);
}

void	change_window(t_data *fdf_data, int sens)
{
	if ((sens == 1 && fdf_data->argv[fdf_data->actual_ar + 1])
		|| (sens == 2 && fdf_data->actual_ar > 1))
	{
		mlx_destroy_image(fdf_data->mlx, fdf_data->img);
		fdf_data->img = NULL;
		mlx_destroy_window(fdf_data->mlx, fdf_data->win);
		fdf_data->zoom = 1;
		if (sens == 1)
			fdf_data->actual_ar++;
		else
			fdf_data->actual_ar--;
		free_point(&fdf_data->list_point);
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
}

void	zoom(t_data *fdf_data, int key)
{
	if ((key == 24 && fdf_data->zoom == 1)
		|| (key == 27 && fdf_data->zoom >= 2))
	{
		mlx_clear_window(fdf_data->mlx, fdf_data->win);
		mlx_destroy_image(fdf_data->mlx, fdf_data->img);
		fdf_data->img = NULL;
		if (key == 24)
		{
			fdf_data->win_decal_x -= (fdf_data->win_x / 2) / fdf_data->zoom;
			fdf_data->win_decal_y -= (fdf_data->win_y / 2) / fdf_data->zoom;
			fdf_data->zoom++;
		}
		else
		{
			fdf_data->zoom--;
			fdf_data->win_decal_x += (fdf_data->win_x / 2) / fdf_data->zoom;
			fdf_data->win_decal_y += (fdf_data->win_y / 2) / fdf_data->zoom;
		}
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
}

void	move(t_data *fdf_data, int key)
{
	if (key == 0)
		fdf_data->win_decal_x -= 10 * fdf_data->zoom;
	if (key == 2)
		fdf_data->win_decal_x += 10 * fdf_data->zoom;
	if (key == 13)
		fdf_data->win_decal_y -= 10 * fdf_data->zoom;
	if (key == 1)
		fdf_data->win_decal_y += 10 * fdf_data->zoom;
	if (key == 8)
	{
		fdf_data->win_decal_x = 0;
		fdf_data->win_decal_y = 0;
		if (fdf_data->zoom == 2)
		{
			fdf_data->win_decal_x -= (fdf_data->win_x / 2);
			fdf_data->win_decal_y -= (fdf_data->win_y / 2);
		}
	}
	mlx_clear_window(fdf_data->mlx, fdf_data->win);
	call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
}
