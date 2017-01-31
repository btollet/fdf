/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 11:31:57 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/31 15:09:23 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_data *fdf_data)
{
	if (key == 53)
		exit(1);
	if (key == 124)
		change_window(fdf_data, 1);
	if (key == 123)
		change_window(fdf_data, 2);
	if (key == 24)
		zoom(fdf_data, 1);
	if (key == 27)
		zoom(fdf_data, 2);
	return (0);
}

void	change_window(t_data *fdf_data, int sens)
{
	if (sens == 1 && fdf_data->actual_ar < fdf_data->nb_ar)
	{
		mlx_destroy_window(fdf_data->mlx, fdf_data->win);
		fdf_data->zoom = 1;
		fdf_data->actual_ar++;
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
	if (sens == 2 && fdf_data->actual_ar > 1)
	{
		mlx_destroy_window(fdf_data->mlx, fdf_data->win);
		fdf_data->zoom = 1;
		fdf_data->actual_ar--;
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
}

void	zoom(t_data *fdf_data, int sens)
{
	if (sens == 1 && fdf_data->zoom == 1)
	{
		mlx_destroy_window(fdf_data->mlx, fdf_data->win);
		fdf_data->zoom++;
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
	if (sens == 2 && fdf_data->zoom >= 2)
	{
		mlx_destroy_window(fdf_data->mlx, fdf_data->win);
		fdf_data->zoom--;
		call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
	}
}

