/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:56:12 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/29 14:34:38 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int nb_ar, char **argv)
{
	int		line_len;
	t_data	fdf_data;
	t_point	*list_point;
	t_point	*test;

	if (nb_ar >= 2)
	{
		if (nb_ar != 2)
		{
			ft_putendl("Too many arguments");
			return (0);
		}
		if (!(list_point = read_file(argv[1])))
		{
			ft_putendl("Error file read");
			return (0);
		}
	}
	else
	{
		ft_putendl("No file");
		return (0);
	}
	
	line_len = list_point->line_len;
		fdf_data.win_x = 10;
	fdf_data.win_y = 10;
	fdf_data.decal_y = 0;
	fdf_data.decal_x = 0;
	fdf_data = fdf_init(list_point, fdf_data);
	while (list_point->next)
	{
		if (!list_point->id)
			list_point = list_point->next;
		test = list_point->next;
		if (test->x > list_point->x)
			draw_line(fdf_data, list_point, test);
		while (test && test->id != list_point->id + line_len)
			test = test->next;
		if (test)
			draw_line(fdf_data, list_point, test);
		list_point = list_point->next;
	}
	mlx_key_hook(fdf_data.win, key_press, 0);
	mlx_loop(fdf_data.mlx);
	return (1);
}
