/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:58:46 by brmohamm          #+#    #+#             */
/*   Updated: 2021/12/15 15:24:18 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	g_d;
char	g_w;
char	g_a;
char	g_s;

void	door_open(t_data *data, char temp)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (data->result[i] != '\0')
	{
		while (data->result[i][t] != '\0')
		{
			if (data->result[i][t] == temp)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->door_close, t * 80, i * 80);
			}
			t++;
		}
		t = 0;
		i++;
	}
}

int	mouse(void)
{
	exit(0);
	return (0);
}

int	key(int key, t_data *data)
{
	g_d = data->result[(data->high / 80)][(data->whith / 80) + 1];
	g_w = data->result[(data->high / 80) - 1][data->whith / 80];
	g_a = data->result[data->high / 80][(data->whith / 80) - 1];
	g_s = data->result[(data->high / 80) + 1][data->whith / 80];
	if (key == 53)
		exit(0);
	if (data->win == 0 && (key == 2 || key == 124) && (g_d == '0'
			|| g_d == 'P' || g_d == 'C' || g_d == 'E' || g_d == 'A'))
		move(data, g_d, 0, 1);
	if (data->win == 0 && (key == 0 || key == 123) && (g_a == '0'
			|| g_a == 'P' || g_a == 'C' || g_a == 'E' || g_a == 'A'))
		move(data, g_a, 0, -1);
	if (data->win == 0 && (key == 13 || key == 126) && (g_w == '0'
			|| g_w == 'P' || g_w == 'C' || g_w == 'E' || g_w == 'A'))
		move(data, g_w, -1, 0);
	if (data->win == 0 && (key == 1 || key == 125) && (g_s == '0'
			|| g_s == 'P' || g_s == 'C' || g_s == 'E' || g_s == 'A'))
		move(data, g_s, 1, 0);
	if (data->coin_point == 0)
		door_open(data, 'E');
	return (0);
}

void	check(char *str)
{
	int		i;
	char	*ber;
	int		l;

	ber = "reb.";
	i = 0;
	while (str[i])
			i++;
	i--;
	l = 0;
	while (ber[l] != '\0')
	{
		if (ber[l] != str[i])
			exit(0);
		l++;
		i--;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;
	int		error;

	check(av[1]);
	error = 1;
	data.bufer = malloc(1000);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		error = read(fd, data.bufer, 1000);
		data.bufer[error] = '\0';
		close(fd);
		data.result = ft_split(data.bufer, '\n');
		error_game(data.result, error, fd, data.bufer);
		respone(&data);
		respone_obj(&data);
		mlx_key_hook(data.mlx_win, &key, &data);
		mlx_hook(data.mlx_win, 17, (1L << 17), &mouse, &data);
		mlx_loop_hook(data.mlx, &hole_move, &data);
		mlx_loop(data.mlx);
		free(data.mlx);
	}
	return (0);
}
