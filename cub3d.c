#include "cub3d.h"


void	clean_line(t_info *info, char *line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	i--;
	while (is_space(line[i]))
		i--;
	if (info->wight < ++i)
		info->wight = i;
}

void    new_maps(t_info *info)
{
	int	i;

	i = 0;
	while (info->maps[i])
	{
		clean_line(info, info->maps[i]);
		info->maps[i] = strdup_new_map(info->maps[i], info);
		i++;
	}	
}

int	check_valide_mur(t_info *info)
{
	int i;
	int j;

	i = 1;
	while(info->maps[i] && i < info->last_line)
	{
		j = 1;
		while(info->maps[i][j])
		{
			if(info->maps[i][j] == '0')
			{
				if (!check_valid_caractere(info->maps[i + 1][j]) 
					|| !check_valid_caractere(info->maps[i - 1][j])
					|| !check_valid_caractere(info->maps[i][j + 1])
					|| !check_valid_caractere(info->maps[i][j - 1]))
						print_error("invalide maps\n");
			}
			j++;
		}
		i++;
	}
	return (1);
}

int check_element_maps(t_info *info)
{
    int i;

    i = 0;
    while(info->maps[i])
    {
        if(!check_valide_mur(info))
			return (0);
		i++;
    }
	return (1);
}
int mouve_mouse(int x, int y, t_info *info)
{
	static int a;
	if (x > a)
		info->angle += 0.01;
	else if (x < a)
		info->angle -= 0.01;
	a = x;
	return (0);
}
int main(int ac, char **av)
{
	t_info info;

	info.mlx = NULL;
	info.garbage = NULL;
	if (ac != 2)
		print_error("arguments error\n");
	init_info(&info, ac, av);
	read_maps(&info);
	check_textures_path(&info);
	if (!info.path_ea || !info.path_so || !info.path_we || !info.path_no)
		print_error("path_error\n");
	new_maps(&info);
	check_extention_map(&info);
	check_wall_valide(&info);
	check_nbr_player(&info);
	if (!check_element_maps(&info))
	{
		printf("autre caractere\n");
		return (0);
	}
	init_window(&info);
	info.barbie = "./bluestone1.xpm";
	info.drow_barbie = mlx_xpm_file_to_image(info.mlx, info.barbie, &info.w, &info.h);
	info.image = mlx_get_data_addr(info.drow_barbie, &info.bet_pxl, &info.size_line, &info.endian);
	mlx_hook(info.mlx_win, 17, 0, ft_exit, 0);
	mlx_hook(info.mlx_win, 2, 1L << 0, mouve_player, &info);
	mlx_hook(info.mlx_win, 6, 1 << 6 , mouve_mouse , &info);
	mlx_loop_hook(info.mlx, rendering_2d, &info);
	mlx_loop(info.mlx);
	free_list(&info, 0);
}
