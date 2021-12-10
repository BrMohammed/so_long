#include "so_long.h"

int coin_point = 0;
int win = 0;
int key(int key, t_data *data)
{
	//w=13  s=1  d=2 a=0 
	//up = 126  right = 124 left = 123 down = 125

		if(win == 0 && (key == 2 || key == 124) && (data->result[data->high / 80][(data->whith /80) + 1] == '0' || data->result[data->high / 80][(data->whith /80) + 1] == 'p' 
			|| data->result[data->high / 80][(data->whith /80) + 1] == 'c' || (data->result[data->high / 80][(data->whith /80) + 1] == 'e' && coin_point == 0))) //d or right
		{
			if(data->result[data->high / 80][(data->whith /80) + 1] == 'c')
			{
				data->whith += 80;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
				data->whith -= 80;
				coin_point--;
			}
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
			data->whith += 80;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,data->whith, data->high);
			if(data->result[data->high / 80][(data->whith /80) ] == 'e' && coin_point == 0)
			{
				mlx_destroy_window(data->mlx,data->mlx_win);
			}
				if(coin_point == 0)
					mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_open,data->door_whith, data->door_high);
		}
		if(win == 0 && (key == 0 || key == 123) && (data->result[data->high / 80][(data->whith /80) - 1] == '0' || data->result[data->high / 80][(data->whith /80) - 1] == 'p' 
			|| data->result[data->high / 80][(data->whith /80) - 1] == 'c' || (data->result[data->high / 80][(data->whith /80) - 1] == 'e' && coin_point == 0))) // a or left
		{
			if(data->result[data->high / 80][(data->whith /80) - 1] == 'c')
			{
				data->whith -= 80;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
				data->whith += 80;
				coin_point--;
			}
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
			data->whith -= 80;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,data->whith, data->high);
			if(data->result[data->high / 80][(data->whith /80) ] == 'e' && coin_point == 0)
			{
				mlx_destroy_window(data->mlx,data->mlx_win);
			}
			if(coin_point == 0)
					mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_open,data->door_whith, data->door_high);
		}
		if(win == 0 && (key == 13 || key == 126) && (data->result[(data->high / 80) - 1][data->whith /80] == '0' || data->result[(data->high / 80) - 1][data->whith /80] == 'p' 
			|| data->result[(data->high / 80) - 1][data->whith /80] == 'c' || (data->result[(data->high / 80) - 1][data->whith /80] == 'e' && coin_point == 0))) // w or up
		{
			if(data->result[(data->high / 80) - 1][data->whith /80] == 'c')
			{
				data->high -= 80;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
				data->high += 80;
				coin_point--;
			}
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
			data->high -= 80;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,data->whith, data->high);
			if(data->result[data->high / 80][(data->whith /80) ] == 'e' && coin_point == 0)
			{
				mlx_destroy_window(data->mlx,data->mlx_win);
			}
			if(coin_point == 0)
					mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_open,data->door_whith, data->door_high);
		}
		if(win == 0 && (key == 1 || key == 125) && (data->result[(data->high / 80) + 1][data->whith /80] == '0' || data->result[(data->high / 80) + 1][data->whith /80] == 'p' 
			|| data->result[(data->high / 80) + 1][data->whith /80] == 'c' || (data->result[(data->high / 80) + 1][data->whith /80] == 'e' && coin_point == 0))) // s or down
		{
			if(data->result[(data->high / 80) + 1][data->whith /80] == 'c')
			{
				data->high += 80;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
				data->high -= 80;
				coin_point--;
			}
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->whith, data->high);
			data->high += 80;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,data->whith, data->high);
			if(data->result[data->high / 80][(data->whith /80) ] == 'e' && coin_point == 0)
			{
				mlx_destroy_window(data->mlx,data->mlx_win);
			}
			if(coin_point == 0)
					mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_open,data->door_whith, data->door_high);
		}
		//printf("%d\n",key);
	return(0);
}

int main(int ac, char **av)
{
	//void *mlx;
	//void *mlx_win;
    t_data	data;
	void *walls;
	


    data.player_path = "./assets/idle01.xpm";
	char	*walls_path = "./assets/green.xpm";
	data.plat_path = "./assets/water.xpm";
	data.coin_path = "./assets/coin.xpm";
	data.door_cloce_path = "./assets/closedoor.xpm";
	data.door_open_path = "./assets/opendoor.xpm";

    int		img_width = 80;
	int		img_height = 80;

	//////////////////
	int fd;
	char *bufer;
	int error = 1;

	bufer = malloc(1000);
	if(ac == 2)
	{
		fd = open(av[1],O_RDONLY);
		error = read(fd,bufer,1000);
		bufer[error] = '\0';
	}
	data.result = ft_split(bufer,'\n');
	int x = 0;
	int y = 0;
	while(data.result[y] != '\0')
	{
		while(data.result[0][x] != '\0')
			x++;
		y++;
		
	}
	////////////////////
	fd = 0;
	int whith = 0;
	int high = 0;
	int more = 0;
	int i = 0;


	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx,x*80,y*80,"so_long");


	walls = mlx_xpm_file_to_image(data.mlx, walls_path, &img_width, &img_height);
	data.plat = mlx_xpm_file_to_image(data.mlx, data.plat_path, &img_width, &img_height);
	data.player = mlx_xpm_file_to_image(data.mlx, data.player_path, &img_width, &img_height);
	data.coin = mlx_xpm_file_to_image(data.mlx, data.coin_path, &img_width, &img_height);
	data.door_close = mlx_xpm_file_to_image(data.mlx, data.door_cloce_path, &img_width, &img_height);
	data.door_open = mlx_xpm_file_to_image(data.mlx, data.door_open_path, &img_width, &img_height);
	while(bufer[fd] != '\0')
	{
		
		if(bufer[fd] == '1')
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, walls, whith, high);
			whith += 80;
		}
		else if(bufer[fd] == '0' || bufer[fd] == 'p' || bufer[fd] == 'c' || bufer[fd] == 'e')
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.plat, whith, high);
			if(bufer[fd] == 'p')
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.player, whith, high);
				data.high = high;
				data.whith = whith;
			}
			if(bufer[fd] == 'c')
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.coin, whith, high);
				coin_point++;
			}
			if(bufer[fd] == 'e')
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.door_close, whith, high);
				data.door_high = high;
				data.door_whith = whith;
			}
			whith += 80;
		}
		fd++;
		if(bufer[fd] == '\n')
		{
			high += 80;
			whith = 0;
			//printf("%d\n",high);
		}
	}
	mlx_key_hook(data.mlx_win,key,&data);
   //img.img = mlx_new_image(mlx, 1920, 1080);

    //img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);

    mlx_loop(data.mlx);
}