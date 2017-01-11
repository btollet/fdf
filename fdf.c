/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:56:12 by benjamin          #+#    #+#             */
/*   Updated: 2016/12/27 15:18:28 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main()
{
	void *mlx;
	void *win;
	int test[4];

	test[0] = 0;
	test[1] = 0;
	test[2] = 132;
	test[3] = 359;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "FDF");
	draw_square(mlx, win, test);
	draw_line(mlx, win, test);
	mlx_loop(mlx);
	return (1);
}