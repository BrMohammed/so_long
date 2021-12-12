# include "so_long.h"

void respone(t_data *data)
{
    int x = 0;
	int y = 0;
	while(data->result[y] != '\0')
	{
		while(data->result[0][x] != '\0')
			x++;
		y++;
	}
    data->player_path = "./assets/idle01.xpm";
	data->walls_path = "./assets/green.xpm";
	data->plat_path = "./assets/water.xpm";
	data->coin_path = "./assets/coin.xpm";
	data->door_cloce_path = "./assets/closedoor.xpm";
	data->door_open_path = "./assets/opendoor.xpm";
	data->player_left_path = "./assets/Idle_left.xpm";
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx,x*80,y*80,"so_long");
    data->walls = mlx_xpm_file_to_image(data->mlx, data->walls_path, &data->img_width, &data->img_height);
    data->plat = mlx_xpm_file_to_image(data->mlx, data->plat_path, &data->img_width, &data->img_height);
    data->player = mlx_xpm_file_to_image(data->mlx, data->player_path, &data->img_width, &data->img_height);
    data->coin = mlx_xpm_file_to_image(data->mlx, data->coin_path, &data->img_width, &data->img_height);
    data->door_close = mlx_xpm_file_to_image(data->mlx, data->door_cloce_path, &data->img_width, &data->img_height);
    data->door_open = mlx_xpm_file_to_image(data->mlx, data->door_open_path, &data->img_width, &data->img_height);
    data->player_left = mlx_xpm_file_to_image(data->mlx, data->player_left_path, &data->img_width, &data->img_height);
}
