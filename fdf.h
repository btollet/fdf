/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:56:53 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/02 13:10:08 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 10

# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

typedef struct		s_point
{
	int				id;
	int				x;
	int				y;
	int				line_len;
	int				line_count;
	int				color;
	struct s_point	*next;
}					t_point;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				div_x;
	int				div_y;
	int				color;
}					t_coord;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	int				decal_x;
	int				decal_y;
	int				div_x;
	int				div_y;
	int				zoom;
	int				actual_ar;
	char			**argv;
	t_point			*list_point;
}					t_data;

int					main(int nb_ar, char **argv);
void				call_fonc(t_data fdf_data, char *argv);
void				draw_line(t_data data, t_point *point1, t_point *point2);
void				v_pixel(t_data data, t_coord p1, t_coord p2, t_coord inc);
void				h_pixel(t_data data, t_coord p1, t_coord p2, t_coord inc);
t_point				*read_file(char *file);
t_point				*add_point(int id, int x, int y, char *split);
t_point				*split_to_list(t_point *list_point, char **split, int y);
t_data				fdf_init(t_point *list_point, t_data fdf_data);
t_data				check_win(t_point *list_point, t_data fdf_data);
void				error(char *mes, t_point *list_point);
int					get_color(char *split);
void				free_split(char **split);
t_point				*free_point(t_point **list_point);
int					key_press(int key, t_data *fdf_data);
void				zoom(t_data *fdf_data, int sens);
void				move(t_data *fdf_data, int dir);
void				change_window(t_data *fdf_data, int sens);
void				set_point(t_data fdf_data, t_point *list_point);

#endif
