# include "so_long.h"

void hole_b(t_data *data , char v,int *x ,int *y,int move)
{
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,*x*80,*y*80);
    data->result[*y][*x] = '0';
    if(move == 1)
        *y += 1;
    if(move == 2)
        *y -= 1;
    if(move == 3)
        *x -= 1;
    if(move == 4)
        *x += 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,*x*80,*y*80);
    data->result[*y][*x] = 'a';
    if(v == 'p')
    {
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,*x*80,*y*80);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,*x*80,*y*80);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,*x*80,*y*80);
        data->win = 1;
    }
}

void conditions(t_data *data,int *x,int *y)
{
    static int temp;
    char d ;
	char w ;
	char a ;
	char s ; 

    d = data->result[*y][*x + 1];
    w = data->result[*y - 1][*x];
	a = data->result[*y][*x - 1];
	s = data->result[*y + 1][*x]; 

    if(w == '1' || w == 'c' || w == 'e' || w == 'a')
        temp = 1;
    if(s == '1'|| s == 'c' || s == 'e' || s == 'a')
        temp = 0;
    if(a == '1' || a == 'c' || a == 'e' || a == 'a')
        temp = 2;
    if(d == '1' || d == 'c' || d == 'e' || d == 'a')
        temp = 3;                 
    if ((s == '0' && temp == 1) || (s == 'p' && temp == 1) )
        hole_b(data,s,x,y,1);
    if ((w == '0' && temp == 0) || (w == 'p' && temp == 0))
        hole_b(data,w,x,y,2);
    if ((a == '0' && temp == 3) || (a == 'p' && temp == 3))
        hole_b(data,a,x,y,3);
    if ((d == '0' && temp == 2) || (d == 'p' && temp == 2))
        hole_b(data,d,x,y,4);
}

void flower(t_data *data)
{
    int x  = 0;
    int y  = 0;
    while(data->result[y] != '\0')
	{
		while(data->result[y][x] != '\0')
		{
			if(data->result[y][x] == 'c')
			{
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin1,x*80,y*80);
            }
            x++;
		}
        x = 0;
		y++;
	}
}

int hole_move(t_data *data)
{
    static int i;
    int x ;
    int y ;

    x = 0;
    y = 0;
    if(i == 3000)
    {
        flower(data);
    }
    if(i == 6000 && data->win != 1)
    {
        while(data->result[y] != '\0')
	    {
		    while(data->result[y][x] != '\0')
		    {
			    if(data->result[y][x] == 'a')
			    {
                    conditions(data,&x,&y);
                }
                if(data->result[y][x] == 'c')
                    mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin,x*80,y*80);
                x++;
			}
            x = 0;
			y++;
		}
		i = 0;
	}
    i++;
    return(0);
}