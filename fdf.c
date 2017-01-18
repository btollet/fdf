/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:56:12 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/17 12:05:19 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*fdf_init()
{
	t_data	*fdf_data;

	if ((fdf_data = (t_data *)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	fdf_data->mlx = mlx_init();
	fdf_data->win = mlx_new_window(fdf_data->mlx, 600, 400, "botllet fdf");
	return (fdf_data);
}

int	main(int nb_ar, char **argv)
{
	int		line_len;
	t_data	*fdf_data;
	t_point	*list_point, *test;
	
	if (nb_ar == 2)
		list_point = read_file(argv[1]);
	else
	{
		ft_putendl("No file");
		return (0);
	}
	fdf_data = fdf_init();
	line_len = list_point->line_len;
	while (list_point->next)
	{
		if (!list_point->ID)
			list_point = list_point->next;
		test = list_point->next;
		if (test->x > list_point->x)
			draw_line(fdf_data, list_point, test);
		while (test && test->ID != list_point->ID + line_len)
			test = test->next;
		if (test)
			draw_line(fdf_data, list_point, test);
		list_point = list_point->next;
	}
	mlx_loop(fdf_data->mlx);
	return (1);
}