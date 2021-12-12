# ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>



typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;

	void *player;
	char	*player_path;

	void *player_left;
	char	*player_left_path;

	char	*walls_path;
	void *walls;
	int high;
	int whith;
	
	char	*plat_path;
	void *plat;
	char **result;

	void *coin;
	char *coin_path;

	void *door_close;
	char *door_cloce_path;

	void *door_open;
	char *door_open_path;

	int door_high;
	int door_whith;

	int coin_point ;
	int player_count ;

	int		img_width;
	int		img_height;

}	t_data;

char	**ft_split(char *s, char c);
void move(int win,t_data *data,char v , int y ,int x);
void error_game(t_data *data);
void respone(t_data *data);

#endif