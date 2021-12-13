# include "so_long.h"

int hole_move(t_data *data)
{
    static int i;
    static int temp;
    int x = 0;
    int y = 0;
    if(i == 5000 && data->win != 1)
    {
        while(data->result[y] != '\0')
	    {
		    while(data->result[y][x] != '\0')
		    {
			    if(data->result[y][x] == 'a')
			    {
				    char d = data->result[y][x + 1];
	                char w = data->result[y - 1][x];
	                char a = data->result[y][x - 1];
	                char s = data->result[y + 1][x]; 
                    char t = data->result[y][x];

                    if(w == '1' || w == 'c' || w == 'e' || w == 'a')
                        temp = 1;
                    if(s == '1'|| s == 'c' || s == 'e' || s == 'a')
                        temp = 0;
                    if(a == '1' || a == 'c' || a == 'e' || a == 'a')
                        temp = 2;
                    if(d == '1' || d == 'c' || d == 'e' || d == 'a')
                        temp = 3;

                    if ((s == '0' && temp == 1) || (s == 'p' && temp == 1) )
	                {
                        mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,x*80,y*80);
                        data->result[y][x] = '0';
                        y += 1;
	                    mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,x*80,y*80);
                        data->result[y][x] = 'a';
                        if(s == 'p')
                        {
                            mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,x*80,y*80);
                            mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,x*80,y*80);
		                    mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,x*80,y*80);
                            data->win = 1;
                        }
	                }
                    if ((w == '0' && temp == 0) || (w == 'p' && temp == 0))
	                {
            
                        mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,x*80,y*80);
                        data->result[y][x] = '0';
                        y -= 1;
	                    mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,x*80,y*80);
                        data->result[y][x] = 'a';
                        if(s == 'p')
                        {
                            mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,x*80,y*80);
                            mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,x*80,y*80);
		                    mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,x*80,y*80);
                            data->win = 1;
                        }
                    }
                    if ((a == '0' && temp == 3) || (a == 'p' && temp == 3))
	                {
                        mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,x*80,y*80);
                        data->result[y][x] = '0';
                        x -= 1;
	                    mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,x*80,y*80);
                        data->result[y][x] = 'a';
                        if(s == 'p')
                        {
                            mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,x*80,y*80);
                            mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,x*80,y*80);
		                    mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,x*80,y*80);
                            data->win = 1;
                        }
	                }
                    if ((d == '0' && temp == 2) || (d == 'p' && temp == 2))
	                {
            
                        mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,x*80,y*80);
                        data->result[y][x] = '0';
                        x += 1;
	                    mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,x*80,y*80);
                        data->result[y][x] = 'a';
                        if(s == 'p')
                        {
                            mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,x*80,y*80);
                            mlx_put_image_to_window(data->mlx, data->mlx_win, data->hole,x*80,y*80);
		                    mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,x*80,y*80);
                            data->win = 1;
                        }
                    }
                }
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