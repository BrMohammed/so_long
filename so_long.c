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

int main(int ac, char **av)
{
    t_data	data;
	int temp ;
	int fd;
	int error = 1;

	data.bufer = malloc(1000);
	if(ac == 2)
	{
		fd = open(av[1],O_RDONLY);
		error = read(fd,data.bufer,1000);
		data.bufer[error] = '\0';
	}
	data.result = ft_split(data.bufer,'\n');
	respone(&data);
	respone_obj(&data);
	error_game(&data);
	mlx_key_hook(data.mlx_win,&key,&data);
    mlx_loop(data.mlx);
	free(data.mlx);
}