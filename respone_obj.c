/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   respone_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:31:36 by brmohamm          #+#    #+#             */
/*   Updated: 2021/12/15 01:59:06 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	condetion_double(t_data *data, int *fd, int *whith, int *high)
{
	if (data->bufer[*fd] == 'P')
	{
		data->player_cont++;
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player, *whith, *high);
		data->high = *high;
		data->whith = *whith;
	}
	if (data->bufer[*fd] == 'C')
	{
		data->coin_cont++;
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->coin, *whith, *high);
		data->coin_point++;
	}
	if (data->bufer[*fd] == 'A')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->hole, *whith, *high);
		data->hole_high = *high;
		data->hole_whith = *whith;
	}
}

void	condetion(t_data *data, int *fd, int *whith, int *high)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->plat, *whith, *high);
	condetion_double(data, fd, whith, high);
	if (data->bufer[*fd] == 'E')
	{
		data->door_cont++;
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->door_open, *whith, *high);
		data->door_high = *high;
		data->door_whith = *whith;
	}
	*whith += 80;
}

static void	condetion42(t_data *data, int fd, int *high, int *whith)
{
	if (data->bufer[fd] == '\n')
	{
		*high += 80;
		*whith = 0;
	}
}

void	respone_obj(t_data *data)
{
	int	fd;
	int	whith;
	int	high;

	fd = 0;
	whith = 0;
	high = 0;
	data->coin_point = 0;
	while (data->bufer[fd] != '\0')
	{
		if (data->bufer[fd] == '1')
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->walls, whith, high);
			whith += 80;
		}
		else if (data->bufer[fd] == '0' || data->bufer[fd] == 'P'
			|| data->bufer[fd] == 'C'
			||data->bufer[fd] == 'E' || data->bufer[fd] == 'A')
			condetion(data, &fd, &whith, &high);
		fd++;
		condetion42(data, fd, &high, &whith);
	}
}
