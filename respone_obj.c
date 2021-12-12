# include "so_long.h"

void respone_obj(t_data *data)
{
    int fd = 0;
    int whith = 0;
	int high = 0;
	
	while(data->bufer[fd] != '\0')
	{

		if(data->bufer[fd] == '1')
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->walls, whith, high);
			whith += 80;
		}
		else if(data->bufer[fd] == '0' || data->bufer[fd] == 'p' || data->bufer[fd] == 'c' || data->bufer[fd] == 'e')
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat, whith, high);
			if(data->bufer[fd] == 'p')
			{
				data->player_cont++;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, whith, high);
				data->high = high;
				data->whith = whith;
			}
			if(data->bufer[fd] == 'c')
			{
				data->coin_cont++;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin, whith, high);
				data->coin_point++;
			}
			if(data->bufer[fd] == 'e')
			{
				data->door_cont++;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_open, whith, high);
				data->door_high = high;
				data->door_whith = whith;
			}
			whith += 80;
		}
		fd++;
		if(data->bufer[fd] == '\n')
		{
			high += 80;
			whith = 0;
		}
	}
	if (data->coin_cont < 1 || data->player_cont != 1 || data->door_cont != 1)
	{
		printf("%s\n", "ERROR");
		exit(0);
	}
}