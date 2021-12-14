/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:43:23 by brmohamm          #+#    #+#             */
/*   Updated: 2021/12/14 23:36:29 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	just25(t_data *data, int i, int len)
{
	while (data->result[i][len])
	{
		if (data->result[i][len] == '0')
		{
			printf("%s\n", "ERROR");
			exit(0);
		}
		len++;
	}
}

void	error_while(t_data *data, int i, int len, int lenth_temp)
{
	while (data->result[i][len])
	{
		if (data->result[0][len] == '0' || data->result[i][0] == '0')
		{
			printf("%s\n", "ERROR");
			exit(0);
		}
		if (data->result[i][len] != 'E' && data->result[i][len] != 'A'
		&& data->result[i][len] != 'C' && data->result[i][len] != '1'
		&& data->result[i][len] != 'P' && data->result[i][len] != '0')
		{
			printf("%s\n", "ERROR");
			exit(0);
		}
		len++;
	}
	len--;
	if (data->result[0][len])
		lenth_temp = len;
	if (lenth_temp != len || data->result[i][len] == '0')
	{
		printf("%s\n", "ERROR");
		exit(0);
	}
}

void	error_game(t_data *data)
{
	int	i;
	int	len;
	int	lenth_temp;
	int	lenth;

	i = 0;
	len = 0;
	lenth_temp = 0;
	lenth = 0;
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
	{
		printf("%s\n", "ERROR");
		exit(0);
	}
}
