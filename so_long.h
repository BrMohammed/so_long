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
	int high;
	int whith;
	char	*player_path;
	char	*plat_path;
	void *plat;
	char **result;

	void *coin;
	char *coin_path;

	void *door_close;
	char *door_cloce_path;

	void *door_open;
	char *door_open_path;


}	t_data;





char	**ft_split(char *s, char c);

#endif