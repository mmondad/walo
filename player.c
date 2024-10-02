/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:52:04 by khmessah          #+#    #+#             */
/*   Updated: 2024/09/30 11:04:26 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouve_player(int c, t_info *info)
{
	if (c == 65363)
		info->angle += 0.1;
	if (c == 65361)
		info->angle -= 0.1;
	if (info->angle < 0)
		info->angle += 2 * M_PI;
	if (info->angle > 2 * M_PI)
		info->angle -= 2 * M_PI;
    else if (c == ABOVE)
    {
		if (info->maps[(int)((info->y_p + sin(info->angle) * SPEED) / 60)][(int)((info->x_p + cos(info->angle) * SPEED) / 60)] != '1')
		{
			info->x_p += cos(info->angle) * SPEED;
			info->y_p += sin(info->angle) * SPEED;
		}
    }
    else if (c == LOWEST)
    {
		if (info->maps[(int)((info->y_p - sin(info->angle) * SPEED) / 60)][(int)((info->x_p - cos(info->angle) * SPEED) / 60)] != '1')
		{
			info->x_p -= cos(info->angle) *SPEED;
			info->y_p -= sin(info->angle) *SPEED;
		}
    }
    else if (c == RIGHT)
    {
		if (info->maps[(int)((info->y_p + sin(info->angle + M_PI / 2) * SPEED) / 60)][(int)((info->x_p + cos(info->angle + M_PI / 2) * SPEED) / 60)] != '1')
		{
			info->x_p += cos(info->angle + M_PI / 2) * SPEED;
			info->y_p += sin(info->angle + M_PI / 2)* SPEED;
		}
    }
    else if (c == LEFT)
    {
		if (info->maps[(int)((info->y_p - sin(info->angle + M_PI / 2) * SPEED) / 60)][(int)((info->x_p - cos(info->angle + M_PI / 2) * SPEED) / 60)] != '1')
		{
			info->x_p += cos(info->angle - M_PI / 2) * SPEED;
			info->y_p += sin(info->angle - M_PI / 2) * SPEED;
		}
    }
	else if (c == 65307)
		exit(0);
	return (0);
}

void	render_player(t_info *info, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			my_mlx_pixel_put(info, (info->x_p / MINIMAP_SIZE) + x, (info->y_p / MINIMAP_SIZE) + y, color);
			my_mlx_pixel_put(info, (info->x_p / MINIMAP_SIZE) - x, (info->y_p / MINIMAP_SIZE) + y, color);
			my_mlx_pixel_put(info, (info->x_p / MINIMAP_SIZE) - x, (info->y_p / MINIMAP_SIZE) - y, color);
			my_mlx_pixel_put(info, (info->x_p / MINIMAP_SIZE) + x, (info->y_p / MINIMAP_SIZE) - y, color);
			x++;
		}
		y++;
	}
}