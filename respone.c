# include "so_long.h"

void path(t_data *data)
{
    data->player_path = "./assets/idle01.xpm";
	data->walls_path = "./assets/square2.xpm";
	data->plat_path = "./assets/pack.xpm";
	data->coin_path = "./assets/f1.xpm";
    data->coin_path1 = "./assets/f2.xpm";
	data->door_cloce_path = "./assets/closedoor.xpm";
	data->door_open_path = "./assets/opendoor.xpm";
	data->player_left_path = "./assets/Idle_left.xpm";
    data->dead_path = "./assets/dead.xpm";
    data->hole_path = "./assets/hole.xpm";
}

void number_b(t_data *data)
{
    data->number.number0_path = "./assets/0.xpm";
    data->number.number1_path = "./assets/1.xpm";
    data->number.number2_path = "./assets/2.xpm";
    data->number.number3_path = "./assets/3.xpm";
    data->number.number4_path = "./assets/4.xpm";
    data->number.number5_path = "./assets/5.xpm";
    data->number.number6_path = "./assets/6.xpm";
    data->number.number7_path = "./assets/7.xpm";
    data->number.number8_path = "./assets/8.xpm";
    data->number.number9_path = "./assets/9.xpm";
    data->number.number0 = mlx_xpm_file_to_image(data->mlx, data->number.number0_path, &data->img_width, &data->img_height);
    data->number.number1 = mlx_xpm_file_to_image(data->mlx, data->number.number1_path, &data->img_width, &data->img_height);
    data->number.number2 = mlx_xpm_file_to_image(data->mlx, data->number.number2_path, &data->img_width, &data->img_height);
    data->number.number3 = mlx_xpm_file_to_image(data->mlx, data->number.number3_path, &data->img_width, &data->img_height);
    data->number.number4 = mlx_xpm_file_to_image(data->mlx, data->number.number4_path, &data->img_width, &data->img_height);
    data->number.number5 = mlx_xpm_file_to_image(data->mlx, data->number.number5_path, &data->img_width, &data->img_height);
    data->number.number6 = mlx_xpm_file_to_image(data->mlx, data->number.number6_path, &data->img_width, &data->img_height);
    data->number.number7 = mlx_xpm_file_to_image(data->mlx, data->number.number7_path, &data->img_width, &data->img_height);
    data->number.number8 = mlx_xpm_file_to_image(data->mlx, data->number.number8_path, &data->img_width, &data->img_height);
    data->number.number9 = mlx_xpm_file_to_image(data->mlx, data->number.number9_path, &data->img_width, &data->img_height);
    
}
void respone(t_data *data)
{
    int x ;
	int y;

    x = 0;
    y = 0;
	while(data->result[y] != '\0')
	{
		while(data->result[0][x] != '\0')
			x++;
		y++;
	}
    data->mlx = mlx_init();
    if(y > 19 || x > 36)
    {
        printf("%s\n","ERROR");
		exit(0);
    }
    data->mlx_win = mlx_new_window(data->mlx,x*80,y*80,"so_long");
    path(data);
    number_b(data);
    data->walls = mlx_xpm_file_to_image(data->mlx, data->walls_path, &data->img_width, &data->img_height);
    data->plat = mlx_xpm_file_to_image(data->mlx, data->plat_path, &data->img_width, &data->img_height);
    data->player = mlx_xpm_file_to_image(data->mlx, data->player_path, &data->img_width, &data->img_height);
    data->coin = mlx_xpm_file_to_image(data->mlx, data->coin_path, &data->img_width, &data->img_height);
    data->coin1 = mlx_xpm_file_to_image(data->mlx, data->coin_path1, &data->img_width, &data->img_height);
    data->door_close = mlx_xpm_file_to_image(data->mlx, data->door_cloce_path, &data->img_width, &data->img_height);
    data->door_open = mlx_xpm_file_to_image(data->mlx, data->door_open_path, &data->img_width, &data->img_height);
    data->player_left = mlx_xpm_file_to_image(data->mlx, data->player_left_path, &data->img_width, &data->img_height);
    data->dead = mlx_xpm_file_to_image(data->mlx, data->dead_path, &data->img_width, &data->img_height);
    data->hole = mlx_xpm_file_to_image(data->mlx, data->hole_path, &data->img_width, &data->img_height);
}
