/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:43:23 by brmohamm          #+#    #+#             */
/*   Updated: 2021/12/15 15:01:11 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void)
{
	printf("%s\n", "ERROR");
	exit(0);
}

void	just25(char **c, int i)
{
	int	len = 0;
	while (c[i][len])
	{
		if (c[i][len] == '0')
		{
			print_error();
		}
		len++;
	}
}

void	error_while(char **c, int i)
{
	int	len = 0;
	int	lenth_temp = 0;
	while (c[i][len])
	{
		if (c[0][len] == '0' || c[i][0] == '0')
			print_error();
		if (c[i][len] != 'E' && c[i][len] != 'A'
		&& c[i][len] != 'C' && c[i][len] != '1'
		&& c[i][len] != 'P' && c[i][len] != '0')
			print_error();
		len++;
	if (c[0][len] != '\0')
		lenth_temp = len;
	}
	len--;
	if (lenth_temp != len || c[i][len] == '0')
		print_error();
}

void	error_game(char **c, int error, int fd, char *str)
{
	int	i;
	int	lenth;

	i = 0;
	lenth = 0;
	if (error <= 0)
		print_error();
	while (c[i])
	{
		error_while(c, i);
		i++;
	}
	i--;
	just25(c, i);
	if (fd == -1)
		print_error();
	i = 0;
	while (str[i])
	{
		if(str[i] == '\n' && str[i + 1] == '\n')
			print_error();
		i++;
	}
	i--;
	if(str[i] == '\n')
		print_error();
}
