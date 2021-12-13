# include "so_long.h"

void door_open(t_data *data,char temp,int *x,int *y)
{
	int i  = 0;
	int t = 0;
	while(data->result[i] != '\0')
	{
		while(data->result[i][t] != '\0')
		{
			if(data->result[i][t] == temp)
			{
				*x = t;
                *y = i;
			}
			t++;
		}
		t = 0;
		i++;
	}
}

int hole_move(t_data *data)
{
    static int i;
    static int temp;
	char d = data->result[(data->hole_high / 80)][(data->hole_whith /80) + 1];
	char w = data->result[(data->hole_high / 80) - 1][data->hole_whith /80];
	char a = data->result[data->hole_high / 80][(data->hole_whith /80) - 1];
	char s = data->result[(data->hole_high / 80) + 1][data->hole_whith /80]; 
    char t = data->result[(data->hole_high / 80)][(data->hole_whith /80)];

    int x;
    int y;
    
  
        
    if(w == '1')
        temp = 1;
    if(s == '1')
        temp = 0;
    if(a == '1')
        temp = 2;
    if(d == '1')
        temp = 3;
    if(i == 5000 && data->win != 1)
    {
        if ((s == '0' && temp == 1) || (s == 'p' && temp == 1) )
	    {
            mlx_put_image_to_window(data->mlx, data->mlx_win, data->door_close,t*80,i*80);
            mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->hole_whith, data->hole_high);
            data->result[(data->hole_high / 80)][(data->hole_whith /80)] = '0';
            data->hole_high = data->hole_high + 80;
	        mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,data->hole_whith, data->hole_high);
            data->result[(data->hole_high / 80)][(data->hole_whith /80)] = 'a';
            if(s == 'p')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->hole_whith, data->hole_high);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,data->whith, data->high);
		        mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,data->hole_whith, data->hole_high);
                data->win = 1;
            }
	    }
        if ((w == '0' && temp == 0) || (w == 'p' && temp == 0))
	    {
            
            mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->hole_whith, data->hole_high);
            data->result[(data->hole_high / 80)][(data->hole_whith /80)] = '0';
            data->hole_high = data->hole_high - 80;
	        mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,data->hole_whith, data->hole_high);
            data->result[(data->hole_high / 80)][(data->hole_whith /80)] = 'a';
             if(w == 'p')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->hole_whith, data->hole_high);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,data->whith, data->high);
		        mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,data->hole_whith, data->hole_high);
                data->win = 1;
            }
        }
        if ((a == '0' && temp == 3) || (a == 'p' && temp == 3))
	    {
            mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->hole_whith, data->hole_high);
            data->result[(data->hole_high / 80)][(data->hole_whith /80)] = '0';
            data->hole_whith = data->hole_whith - 80;
	        mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,data->hole_whith, data->hole_high);
            data->result[(data->hole_high / 80)][(data->hole_whith /80)] = 'a';
            if(a == 'p')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->hole_whith, data->hole_high);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,data->whith, data->high);
		        mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,data->hole_whith, data->hole_high);
                data->win = 1;
            }
	    }
        if ((d == '0' && temp == 2) || (d == 'p' && temp == 2))
	    {
            
            mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->hole_whith, data->hole_high);
            data->result[(data->hole_high / 80)][(data->hole_whith /80)] = '0';
            data->hole_whith = data->hole_whith + 80;
	        mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,data->hole_whith, data->hole_high);
            data->result[(data->hole_high / 80)][(data->hole_whith /80)] = 'a';
             if(d == 'p')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,data->hole_whith, data->hole_high);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,data->whith, data->high);
		        mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,data->hole_whith, data->hole_high);
                data->win = 1;
            }
        }
        i = 0;
    }
    i++;
    
    return(0);
}