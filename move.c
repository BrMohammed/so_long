/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:22:42 by brmohamm          #+#    #+#             */
/*   Updated: 2021/12/16 20:52:38 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_show_count(t_data *data)
{
	char	*c;
	int		i;
	int		t;
	int		v;

	i = 0;
	t = 0;
	v = 0;
	c = ft_itoa(data->player_count);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->walls, 0, 0);
	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0xFFFFf, c);
	free(c);
}

static void	condetion42(char v, t_data *data, int y, int x)
{
	int	w;

	w = 80;
	if (x == -1 || y == -1)
		w *= -1;
	if (v == '0' || v == 'C' || v == 'P')
	{
		data->result[(data->high / 80)][(data->whith / 80)] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,
			data->whith, data->high);
		if (x == -1 || x == 1)
			data->whith = data->whith + w;
		if (y == -1 || y == 1)
			data->high = data->high + w;
		if (x == -1)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left,
				data->whith, data->high);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player, data->whith, data->high);
			data->result[(data->high / 80)][(data->whith / 80)] = 'P';
	}
}

void	move(t_data *data, char v, int y, int x)
{
	int	img_width;
	int	img_height;

	img_width = 80;
	img_height = 80;
	data->player_count ++;
	move_show_count(data);
	if (v == 'E' && data->coin_point == 0)
		exit(0);
	move_to_c(v, data, y, x);
	condetion42(v, data, y, x);
	if (v == 'A')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,
			data->whith, data->high);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,
			data->whith, data->high);
		data->win = 1;
	}
}
