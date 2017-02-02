/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:56:12 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/02 13:10:20 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int nb_ar, char **argv)
{
	t_data	fdf_data;

	fdf_data.list_point = NULL;
	fdf_data.zoom = 1;
	fdf_data.actual_ar = 1;
	fdf_data.argv = argv;
	if (nb_ar >= 2)
		call_fonc(fdf_data, argv[1]);
	else
	{
		ft_putendl("Usage: ./fdf <filename>");
		return (0);
	}
	return (1);
}

void	call_fonc(t_data fdf_data, char *argv)
{
	t_point	*list_point;

	if (!fdf_data.list_point)
	{
		if (!(list_point = read_file(argv)))
		{
			ft_putendl("Error file read.");
			exit(1);
		}
		fdf_data = fdf_init(list_point, fdf_data);
		fdf_data.list_point = list_point;
	}
	else
		list_point = fdf_data.list_point;
	set_point(fdf_data, list_point);
	mlx_key_hook(fdf_data.win, key_press, &fdf_data);
	mlx_loop(fdf_data.mlx);
}
