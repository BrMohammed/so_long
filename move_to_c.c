/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:26:17 by brmohamm          #+#    #+#             */
/*   Updated: 2021/12/18 23:32:22 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	condetion(t_data *data, int x, int y)
{
	int	w;
	int	z;

	w = 80;
	z = -80;
	if (x == -1 || y == -1)
	{
		w *= -1;
		z *= -1;
	}
	if (x == -1 || x == 1)
	{
		data->whith = data->whith + w;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,
			data->whith, data->high);
		data->whith = data->whith + z;
	}
	if (y == -1 || y == 1)
	{
		data->high = data->high + w;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,
			data->whith, data->high);
		data->high = data->high + z;
	}
}

void	move_to_c(char v, t_data *data, int y, int x)
{
	if (v == 'C')
	{
		data->result[(data->high / 80) + y][(data->whith / 80) + x] = '0';
		condetion(data, x, y);
		data->coin_point--;
	}
}
