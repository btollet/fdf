/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 11:31:57 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/27 12:09:35 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_data *fdf_data)
{
	if (key == 53)
	{
		exit(1);
	}
	if (key == 124)
	{
		if (fdf_data->actual_ar < fdf_data->nb_ar)
		{
			mlx_destroy_window(fdf_data->mlx, fdf_data->win);
			fdf_data->actual_ar++;
			call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
		}
	}
	if (key == 123)
	{
		if (fdf_data->actual_ar > 1)
		{
			mlx_destroy_window(fdf_data->mlx, fdf_data->win);
			fdf_data->actual_ar--;
			call_fonc(*fdf_data, fdf_data->argv[fdf_data->actual_ar]);
		}
	}
	return (0);
}
