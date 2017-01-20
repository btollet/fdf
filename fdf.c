/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:56:12 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/20 09:47:45 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int nb_ar, char **argv)
{
	int		line_len;
	int		decal;
	t_data	fdf_data;
	t_point	*list_point;
	t_point	*test;

	if (nb_ar >= 2)
	{
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
	fdf_data = fdf_init(list_point);
	decal = fdf_data.decal;
	while (list_point->next)
	{
		if (!list_point->id)
			list_point = list_point->next;
		test = list_point->next;
		if (test->x > list_point->x)
			draw_line(fdf_data, list_point, test, decal);
		while (test && test->id != list_point->id + line_len)
			test = test->next;
		if (test)
			draw_line(fdf_data, list_point, test, decal);
		list_point = list_point->next;
	}
	mlx_loop(fdf_data.mlx);
	return (1);
}
