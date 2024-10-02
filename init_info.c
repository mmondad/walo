#include "cub3d.h"

void    init_info(t_info *info, int ac, char **av)
{
    info->ac = ac;
    info->wight = 0;
    info->map_name = av[1];
    info->path_ea = NULL;
    info->tmp = 0;
    info->path_no = NULL;
    info->path_we = NULL;
    info->path_so = NULL;
    info->x_p = 0;
    info->y_p = 0;
    info->ceiling_color = NULL;
    info->floor_color = NULL;
    info->last_line = 0;
    info->dir_x = 0;
    info->dir_y = 0;
    info->c = ft_malloc(sizeof (int) * 3, info);
    info->f = ft_malloc(sizeof (int) * 3, info);
}
