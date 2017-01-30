/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:44:38 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/20 09:45:03 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(char *mes)
{
	ft_putendl(mes);
	exit(1);
}

void		error_free(char *mes, t_point *list_point)
{
	free_point(&list_point);
	ft_putendl(mes);
	exit(1);
}
