#include "so_long.h"
void mouve_to_c(char v,t_data *data,int y,int x)
{
    int w = 80;
	int z = -80;
    if (x == -1 || y == -1)
	{
		w *= -1;
		z *= -1;
	}
    if(v == 'c')
	{
		data->result[(data->high / 80) + y][(data->whith /80) + x] = '0';
		if(x == -1 || x == 1)
		{
			data->whith = data->whith + w;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
			data->whith = data->whith + z;
		}
		if(y == -1 || y == 1)
		{
			data->high =data->high + w;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
			data->high =data->high + z;
		}
		data->coin_point--;
	}
}
void move(t_data *data,char v , int y ,int x)
{
	int w = 80;
	int z = -80;
	int img_width = 80;
	int img_height = 80;
	data->player_count ++;
	printf("%d\n",data->player_count);
	if(v == 'e' && data->coin_point == 0)
		exit(0);
	if (x == -1 || y == -1)
	{
		w *= -1;
		z *= -1;
	}
    mouve_to_c(v,data,y,x);
	if(v == '0' || v == 'c' || v == 'p')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
		if(x == -1 || x == 1)
			data->whith =data->whith + w;
		if(y == -1 || y == 1)
			data->high = data->high + w;
		if(x == -1 )
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left,data->whith, data->high);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,data->whith, data->high);
	}
	if (v == 'a')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,data->whith, data->high);
		data->win = 1;
	}
}