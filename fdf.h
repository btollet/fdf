/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:56:53 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/25 18:14:08 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 20

# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

typedef struct		s_point
{
	int				id;
	int				x;
	int				y;
	int				z;
	int				line_len;
	int				line_count;
	int				color;
	struct s_point	*next;
}					t_point;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				color;
}					t_coord;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	int				decal;
	int				div;
}					t_data;

int					main(int nb_ar, char **argv);
void				draw_square(void *mlx, void *win, int *pos);
void				draw_line(t_data data, t_point *point1, t_point *point2, int decal);
void				v_pixel(t_data data, t_coord p1, t_coord p2, t_coord inc);
void				h_pixel(t_data data, t_coord p1, t_coord p2, t_coord inc);
t_point				*read_file(char *file);
t_point				*add_point(int id, int x, int y, char *split);
t_point				*split_to_list(t_point *list_point, char **split, int y);
t_data				fdf_init(t_point *list_point);
t_data				check_win(t_point *list_point);
void				error(char *mes);
int					get_color(char *split);
char				*new_init(char *split);
void				free_split(char **split);

#endif
