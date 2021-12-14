#include "so_long.h"

void error_while(t_data *data,int i,int len,int lenth_temp)
{
    while(data->result[i][len])
	{
		if(data->result[0][len] == '0' || data->result[i][0] == '0')
		{
			printf("%s\n","ERROR");
			exit(0);
		}
		if(data->result[i][len] != 'E' && data->result[i][len] != 'A' && data->result[i][len] != 'C' 
		&& data->result[i][len] != '1' && data->result[i][len] != 'P' && data->result[i][len] != '0') 
		{
			printf("%s\n","ERROR");
			exit(0);
		}
		len++;
		
	}
	len--;
	if(data->result[0][len])
	{
		lenth_temp = len;
	}
	if(lenth_temp != len || data->result[i][len] == '0')
	{
		printf("%s\n","ERROR");
		exit(0);
	}
}
void error_game(t_data *data)
{
	int i = 0;
	int len = 0;
	int lenth_temp = 0;
	int lenth = 0;

	while (data->result[i])
	{
		len = 0;
        error_while(data,i,len,lenth_temp);
		i++;
	}
	i--;
	len = 0;
	while(data->result[i][len])
	{
		if(data->result[i][len] == '0')
		{
			printf("%s\n","ERROR");
			exit(0);
		}
		len++;
	}
	if (data->coin_cont < 1 || data->player_cont != 1)
	{
		printf("%s\n", "ERROR");
		exit(0);
	}
}