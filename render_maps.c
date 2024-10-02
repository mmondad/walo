/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:54:25 by khmessah          #+#    #+#             */
/*   Updated: 2024/09/30 16:24:34 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    put_pixels_as_image(t_info *info, int i, int j, long color)
{
	int x;
	int y;

	x = 0;
	while (x < MULT  - 1)
	{
		y = 0;
		while (y < MULT - 1)
		{
			my_mlx_pixel_put(info, (j * MULT) + y, (i * MULT) + x, color);
			y++;
		}
		x++;
	}
}

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;
	if (y < 0 || y > ((info->last_line + 1)* 60) || x < 0 || x > (info->wight * 60))
		return ;
	dst = info->save + (y * info->line_length + x * (info->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int    rendering_2d(t_info *info)
{
	int i;
	int j;

	info->img = mlx_new_image(info->mlx, info->wight * TILE_SIZE, (info->last_line + 1) * TILE_SIZE);
	info->save = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->line_length,
								&info->endian);
	if (info->angle < 0)
		info->angle += 2 * M_PI;
	if (info->angle > 2 * M_PI)
		info->angle -= 2 * M_PI;
	i = 0;
	while (i <= info->last_line)
	{
		j = 0;
		while (j < info->wight)
		{
			if (info->maps[i][j] == '1')
				put_pixels_as_image(info, i, j, 0xff0080);
			if (info->maps[i][j] == '0' || is_player(info->maps[i][j]))
				put_pixels_as_image(info, i, j, 0xf09990);
			if ( j < info->wight && i <= info->last_line && is_player(info->maps[i][j]))
			{
				if(!info->x_p)
				{
					info->y_p = i * TILE_SIZE + 2;
					info->x_p = j * TILE_SIZE + 2;
					info->player = info->maps[i][j];
					init_angle(info);
				}
			}
			j++;
		}
		i++;
	}
	draw_vector(info);
	render_player(info, 0xf8f7e2);
	// draw_fov(info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
	mlx_destroy_image (info->mlx, info->img);
	return (0);
}
