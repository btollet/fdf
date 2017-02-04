/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:03:27 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/04 16:19:47 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_color(t_coord *inc ,t_point *p1, t_point *p2)
{
	char *color;

	if (!p1->color && !p2->color)
	{
		inc->color[0] = 255;
		inc->color[1] = 255;
		inc->color[2] = 255;
	}
	else 
	{
		if (!p1->color)
			color = p2->color;
		else if (!p2->color)
			color = p1->color;
		else
		{
			if (ft_strcmp(p1->color, p2->color) > 0)
				color = p1->color;
			else
				color = p2->color;
		}
		inc->color[0] = get_color(color, 1);
		inc->color[1] = get_color(color, 2);
		inc->color[2] = get_color(color, 3);
	}
}

int		get_color(char *color, int rgb)
{
	int			result;
	int			rc;
	int			i;
	
	if (!color)
		return (result = 255);
	if (rgb == 1)
		i = ft_strlen(color) - 1;
	if (rgb == 2)
		i = ft_strlen(color) - 3;
	if (rgb == 3)
		i = ft_strlen(color) - 5;
	if (i < 0)
		return (result = 0);
	result = 0;
	rc = 0;
	while (rc <= 1)
	{
		if (color[i] >= 'a' && color[i] <= 'f')
			result += (color[i] - 'a' + 10) * (int)pow(16, rc);
		if (color[i] >= 'A' && color[i] <= 'F')
			result += (color[i] - 'A' + 10) * (int)pow(16, rc);
		if (color[i] >= '1' && color[i] <= '9')
			result += (color[i] - '0') * (int)pow(16, rc);
		rc++;
		i--;
	}
	return (result);
}