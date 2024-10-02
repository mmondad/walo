/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:02:31 by khmessah          #+#    #+#             */
/*   Updated: 2024/09/30 16:00:23 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_info *info)
{
	int x;
	int y;


	if (info->distance_ax / 60 > info->wight || info->distance_ax < 0)
		return ;
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			my_mlx_pixel_put(info, info->distance_ax + x, info->distance_ay + y, 0x5f0000);
			x++;
		}
		y++;
	}
}

void	draw_square_t(t_info *info)
{
	int x;
	int y;

	if (info->distance_ty / 60 > info->last_line + 1 || info->distance_ty < 0)
		return ;
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			my_mlx_pixel_put(info, info->distance_tx + x, info->distance_ty + y, 0x03fcf4);
			x++;
		}
		y++;
	}
}

double	norm(double	angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	render_minimap(t_info *info)
{
	int i;
	int j;

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
			// if ( j < info->wight && i <= info->last_line && is_player(info->maps[i][j]))
			// {

			// }
			j++;
		}
		i++;
	}
}

void	draw_vector(t_info *info)
{
	int		color;
	double	rad = (30 * M_PI / 180);
	int		c;
	double	count = - M_PI / 6;
	double lenght = 0;
	double	point_depart = 0;
	double z = 0;

    c = (WIDTH * 60) / 180;
	while (count < M_PI / 6)
	{
		conditions(info, norm(info->angle + count));
        calcul_distance(info, norm(info->angle + count));
		lenght = (60 / (info->size * cos(count))) * ((WIDTH/ 2) / tan(0.523599));
		point_depart = (HEIGHT / 2) - (lenght / 2);
		double j = 0;
		double step = (double)60 / (double)lenght;
		int yy = 0;
		while (yy < point_depart)
		{
			// if (!(z <= (info->wight * MULT) && yy <= ((info->last_line + 1) * MULT)))
				my_mlx_pixel_put(info, z, yy,  info->c_color_int);
			yy++;
		}
		int var = point_depart;
		int var2;
		while (point_depart <= lenght  + var)
		{
			int yyy;
			int xxx;
			if (info->flag == 0)
			{
				xxx = (int)info->intersection_x % 60;
				yyy = j;
			}
			else
			{
				yyy = j;
				xxx = (int)info->intersection_y % 60;
			}
			var2 = ((yyy * info->size_line) + (xxx * (info->bet_pxl / 8)));
			color = *(int*)(info->image + var2);
			// if (!(z <= (info->wight * MULT) && point_depart <= ((info->last_line + 1) * MULT)))
				my_mlx_pixel_put(info, z, point_depart,  color);
			point_depart++;
			j += step;
		}
		while (point_depart < HEIGHT)
		{
			// if (!(z <= (info->wight * MULT) && point_depart <= ((info->last_line + 1) * MULT)))
				my_mlx_pixel_put(info, z, point_depart,  info->f_color_int);
			point_depart++;
		}
		z += 1;
		count = count + rad / (c * 1.8);
	}
	render_minimap(info);
}