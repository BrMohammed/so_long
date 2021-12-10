#include "so_long.h"

int key(int key, t_data *data)
{
		if(key == 0)
		{
			//mlx_destroy_image(data->mlx, data->player);
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,data->whith, data->high);
			data->whith += 80;;
			printf("%d..%d\n",data->whith,data->high);
		}
			
	return(0);
}

int main(int ac, char **av)
{
	//void *mlx;
	//void *mlx_win;
    t_data	data;
	void *walls;
	void *plat;


    data.player_path = "./assets/idle01.xpm";
	char	*walls_path = "./assets/green.xpm";
	char	*plat_path = "./assets/water.xpm";

    int		img_width ;
	int		img_height ;

	//////////////////
	int fd;
	char *bufer;
	int error = 1;
	char **result;

	bufer = malloc(1000);
	if(ac == 2)
	{
		fd = open(av[1],O_RDONLY);
		error = read(fd,bufer,1000);
		bufer[error] = '\0';
	}
	result = ft_split(bufer,'\n');
	int x = 0;
	int y = 0;
	while(result[y] != '\0')
	{
		while(result[0][x] != '\0')
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
	plat = mlx_xpm_file_to_image(data.mlx, plat_path, &img_width, &img_height);
	data.player = mlx_xpm_file_to_image(data.mlx, data.player_path, &img_width, &img_height);
	while(bufer[fd] != '\0')
	{
		
		if(bufer[fd] == '1')
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, walls, whith, high);
			whith += 80;
		}
		else if(bufer[fd] == '0' || bufer[fd] == 'p')
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, plat, whith, high);
			if(bufer[fd] == 'p')
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.player, whith, high);
				data.high = high;
				data.whith = whith;
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