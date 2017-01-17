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

int	main(int nb_ar, char **argv)
{
	void	*mlx;
	void	*win;
	t_point	*list_point, *test;
	
	if (nb_ar == 2)
		list_point = read_file(argv[1]);
	else
		return (0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 400, "FDF");
	while (list_point->next)
	{
		if (!list_point->ID)
			list_point = list_point->next;
		test = list_point->next;
		if (test->x == list_point->x + DIST)
			draw_line(mlx, win, list_point, test);
		while (test && (test->y != list_point->y + DIST || test->x != list_point->x))
			test = test->next;
		if (test)
			draw_line(mlx, win, list_point, test);
		list_point = list_point->next;
	}
	mlx_loop(mlx);
	return (1);
}