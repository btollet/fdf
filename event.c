/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 11:31:57 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/27 12:09:35 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, void *param)
{
	param = NULL;
ft_putnbr(key);
ft_putendl("");
	if (key == 53)
	{
		exit(1);
	}
	return (1);
}
