#include "so_long.h"

int key(int key, t_data *data)
{
	//w=13  s=1  d=2 a=0 
	//up = 126  right = 124 left = 123 down = 125
	//esc = 53
	int win = 0;
	char d = data->result[(data->high / 80)][(data->whith /80) + 1];
	char w = data->result[(data->high / 80) - 1][data->whith /80];
	char a = data->result[data->high / 80][(data->whith /80) - 1];
	char s = data->result[(data->high / 80) + 1][data->whith /80];
	if (key == 53)
		exit(0);
////////////////d or right
	if(win == 0 && (key == 2 || key == 124) && (d == '0' || d == 'p' || d == 'c' || d == 'e')) 
		move(win,data,d,0,1);
/////////////// a or left
	if(win == 0 && (key == 0 || key == 123) && (a == '0' || a == 'p' || a == 'c' || a == 'e')) 
		move(win,data,a,0,-1);
/////////////// w or up
	if(win == 0 && (key == 13 || key == 126) && (w == '0' || w == 'p' || w == 'c' || w == 'e')) 
		 move(win,data,w,-1,0);
/////////////// s or down
	if(win == 0 && (key == 1 || key == 125) && (s == '0' || s == 'p'|| s == 'c'|| s == 'e'))
	 	move(win,data,s,1,0);
	if(data->coin_point == 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_close,data->door_whith, data->door_high);
		win = 1;
	}
	return (0);
}

void error_game(t_data data)
{
	int i = 0;
	int len = 0;
	int lenth_temp =0;
	int lenth =0;
	while (data.result[i])
	{
		len = 0;
		while(data.result[i][len])
		{
			if(data.result[0][len]== '0')
			{
				printf("%s\n","ERROR");
				exit(0);
			}
			if(data.result[i][0]== '0')
			{
				printf("%s\n","ERROR");
				exit(0);
			}
			len++;
		}
		len--;
		if(data.result[0][len])
		{
			lenth_temp = len;
		}
		if(lenth_temp != len)
		{
			printf("%s\n","ERROR");
			exit(0);
		}
		if(data.result[i][len]== '0')
			{
				printf("%s\n","ERROR");
				exit(0);
			}
		i++;
	}
	i--;
	len = 0;
	while(data.result[i][len])
	{
		if(data.result[i][len]== '0')
		{
			printf("%s\n","ERROR");
			exit(0);
		}
		len++;
	}
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
	data.player_left_path = "./assets/Idle_left.xpm";

    int		img_width = 80;
	int		img_height = 80;
	int temp ;

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

	///////////////////  error  \\\\\\\\\\\\\\\\\\\\\\
	
	error_game(data);


	///////////////////  error  \\\\\\\\\\\\\\\\\\\\\\
	
	////////////////////
	fd = 0;
	int whith = 0;
	int high = 0;
	int more = 0;
	int coin_cont = 0;
	int player_cont = 0;
	int door_cont = 0;
	


	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx,x*80,y*80,"so_long");


	walls = mlx_xpm_file_to_image(data.mlx, walls_path, &img_width, &img_height);
	data.plat = mlx_xpm_file_to_image(data.mlx, data.plat_path, &img_width, &img_height);
	data.player = mlx_xpm_file_to_image(data.mlx, data.player_path, &img_width, &img_height);
	data.coin = mlx_xpm_file_to_image(data.mlx, data.coin_path, &img_width, &img_height);
	data.door_close = mlx_xpm_file_to_image(data.mlx, data.door_cloce_path, &img_width, &img_height);
	data.door_open = mlx_xpm_file_to_image(data.mlx, data.door_open_path, &img_width, &img_height);
	data.player_left = mlx_xpm_file_to_image(data.mlx, data.player_left_path, &img_width, &img_height);
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
				player_cont++;
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.player, whith, high);
				data.high = high;
				data.whith = whith;
			}
			if(bufer[fd] == 'c')
			{
				coin_cont++;
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.coin, whith, high);
				data.coin_point++;
			}
			if(bufer[fd] == 'e')
			{
				door_cont++;
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.door_open, whith, high);
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
	if(coin_cont < 1 || player_cont != 1|| door_cont != 1)
	{
		printf("%s\n","ERROR");
		exit(0);
	}
	mlx_key_hook(data.mlx_win,&key,&data);
   //img.img = mlx_new_image(mlx, 1920, 1080);

    //img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);

	
    mlx_loop(data.mlx);
	free(data.mlx);
}