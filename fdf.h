/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:56:53 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/17 14:11:53 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define DIST 10
# define HEIGHT 10

# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

typedef struct		s_point
{
	int				ID;
	int				x;
	int				y;
	int				z;
	int				line_len;
	struct s_point	*next;
}					t_point;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
}					t_data;

int					main(int nb_ar, char **argv);
void				draw_square(void *mlx, void *win, int *pos);
void				draw_line(t_data *fdf_data, t_point *point1, t_point *point2);
t_point				*read_file(char *file);
t_point				*add_point(int ID, int x, int y, int z);
t_point				*split_to_list(t_point *list_point, char **split, int y);

#endif