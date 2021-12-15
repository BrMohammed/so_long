/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:43:23 by brmohamm          #+#    #+#             */
/*   Updated: 2021/12/15 01:22:05 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_data *data)
{
	printf("%s\n", "ERROR");
	exit(0);
}

void	just25(t_data *data, int i, int len)
{
	while (data->result[i][len])
	{
		if (data->result[i][len] == '0')
		{
			print_error(data);
		}
		len++;
	}
}

void	error_while(t_data *data, int i, int len, int lenth_temp)
{
	while (data->result[i][len])
	{
		if (data->result[0][len] == '0' || data->result[i][0] == '0')
			print_error(data);
		if (data->result[i][len] != 'E' && data->result[i][len] != 'A'
		&& data->result[i][len] != 'C' && data->result[i][len] != '1'
		&& data->result[i][len] != 'P' && data->result[i][len] != '0')
			print_error(data);
		len++;
	}
	len--;
	if (data->result[0][len])
		lenth_temp = len;
	if (lenth_temp != len || data->result[i][len] == '0')
		print_error(data);
}

void	error_game(t_data *data, int error, int ac)
{
	int	i;
	int	len;
	int	lenth_temp;
	int	lenth;

	i = 0;
	len = 0;
	lenth_temp = 0;
	lenth = 0;
	if (ac == 1 || ac > 2 || error <= 0)
		print_error(data);
	while (data->result[i])
	{
		len = 0;
		error_while(data, i, len, lenth_temp);
		i++;
	}
	i--;
	len = 0;
	just25(data, i, len);
	if (data->coin_cont < 1 || data->player_cont != 1)
		print_error(data);
}
