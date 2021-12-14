#include "so_long.h"


void door_open(t_data *data,char temp)
{
	int i  = 0;
	int t = 0;
	while(data->result[i] != '\0')
	{
		while(data->result[i][t] != '\0')
		{
			if(data->result[i][t] == temp)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_close,t*80,i*80);
			}
			t++;
		}
		t = 0;
		i++;
	}
}

int key(int key, t_data *data)
{
	//w=13  s=1  d=2 a=0 
	//up = 126  right = 124 left = 123 down = 125
	//esc = 53
	char d = data->result[(data->high / 80)][(data->whith /80) + 1];
	char w = data->result[(data->high / 80) - 1][data->whith /80];
	char a = data->result[data->high / 80][(data->whith /80) - 1];
	char s = data->result[(data->high / 80) + 1][data->whith /80];
	if (key == 53)
		exit(0);
////////////////d or right
	if(data->win == 0 && (key == 2 || key == 124) && (d == '0' || d == 'P' || d == 'C' || d == 'E' || d == 'A')) 
		move(data,d,0,1);
/////////////// a or left
	if(data->win == 0 && (key == 0 || key == 123) && (a == '0' || a == 'P' || a == 'C' || a == 'E' || a == 'A')) 
		move(data,a,0,-1);
/////////////// w or up
	if(data->win == 0 && (key == 13 || key == 126) && (w == '0' || w == 'P' || w == 'C' || w == 'E' || w == 'A')) 
		 move(data,w,-1,0);
/////////////// s or down
	if(data->win == 0 && (key == 1 || key == 125) && (s == '0' || s == 'P'|| s == 'C'|| s == 'E' || s == 'A'))
	 	move(data,s,1,0);
	if(data->coin_point == 0)
		door_open(data,'E');
	return(0);
}

int main(int ac, char **av)
{
    t_data	data;
	int fd;
	int error;

	error = 1;
	data.bufer = malloc(1000);
	if(ac == 2)
	{
		fd = open(av[1],O_RDONLY);
		error = read(fd,data.bufer,1000);
		data.bufer[error] = '\0';
	}
	if(ac == 1 || ac > 2 || error <= 0)
	{
		printf("%s\n","ERROR");
		exit(0);
	}
	data.result = ft_split(data.bufer,'\n');
	respone(&data);
	respone_obj(&data);
	error_game(&data);
	mlx_key_hook(data.mlx_win,&key,&data);
	mlx_loop_hook(data.mlx,&hole_move,&data);
    mlx_loop(data.mlx);
	//system("leaks a.out");
	free(data.mlx);
}