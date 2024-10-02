/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:00:34 by khmessah          #+#    #+#             */
/*   Updated: 2024/09/26 14:37:36 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	compare_distance(t_info *info, double angle)
{
	double  PD;
	double	PE;
	(void)angle;
	PD = sqrt(((info->x_p - info->hitwall_hor_x) * (info->x_p - info->hitwall_hor_x)) + ((info->y_p - info->hitwall_hor_y) * (info->y_p - info->hitwall_hor_y)));
	PE = sqrt(((info->x_p - info->hitwall_vir_x) * (info->x_p - info->hitwall_vir_x)) + ((info->y_p - info->hitwall_vir_y) * (info->y_p - info->hitwall_vir_y)));
	if (PD > PE)
	{
		info->flag = 1;
		info->intersection_x = ft_abs(info->hitwall_vir_x);
		info->intersection_y = ft_abs(info->hitwall_vir_y);
		info->size = PE;
	}
	else
	{
		info->flag = 0;
        info->intersection_x = ft_abs(info->hitwall_hor_x);
		info->intersection_y = ft_abs(info->hitwall_hor_y);
		info->size = PD;
	}
}

void	check_intersections_hor(t_info *info, double angle)
{
	while ((info->distance_ay / 60 < info->last_line && info->distance_ay / 60 >= 0)
		&& (info->distance_ax / 60 < info->wight && info->distance_ax / 60 >= 0)
			)
	{
		if (info->maps[(int)(info->distance_ay / 60)][(int)(info->distance_ax / 60)] == '1')
		{
			info->hitwall_hor_x = info->distance_ax;
			info->hitwall_hor_y = info->distance_ay;
			return ;
		}
		if (info->check < 3)
		{
			info->distance_ax = (info->distance_ax + (60 / - tan((angle))));
			info->distance_ay -= 60;
		}
		else
		{
			info->distance_ax = (info->distance_ax + (60 /  tan((angle))));
			info->distance_ay += 60;
		}
	}
     info->hitwall_hor_x = info->distance_ax;
	info->hitwall_hor_y = info->distance_ay;
}

void	check_intersections_vir(t_info *info, double angle)
{
	// draw_square_t(info);
	while (((info->distance_ty / 60) < info->last_line && info->distance_ty / 60 >= 0)
		&& ((info->distance_tx / 60) < info->wight && info->distance_tx / 60 >= 0)
			)
	{
		if (info->maps[(int)(info->distance_ty / 60)][(int)(info->distance_tx / 60)] == '1')
		{
			info->hitwall_vir_x = info->distance_tx;
			info->hitwall_vir_y = info->distance_ty;
			return ;
		}
		if (info->check == 3 || info->check == 2)
		{
			info->distance_tx -= 60;
			info->distance_ty = info->y_p - (-info->distance_tx + info->x_p) * tan((angle));
		}
		else
		{
			info->distance_tx += 60;
			info->distance_ty = info->y_p - (-info->distance_tx + info->x_p) * tan((angle));
		}
		// draw_square_t(info);
	}
	info->hitwall_vir_x = info->distance_tx;
	info->hitwall_vir_y = info->distance_ty;
}

void    pinte_point(t_info *info)
{
	int x;
	int y;
	int  color = 0x141414;

	y = 0;
	while (y < 2)
	{
		x = 0;
		while (x < 2)
		{
			my_mlx_pixel_put(info, (info->intersection_x / 3) + x, (info->intersection_y / 3) + y, color);
			x++;
		}
		y++;
	}
}
void	calcul_distance(t_info *info, double angle)
{
	if (info->check == 1 || info->check == 2)
		info->distance_ay = floor(info->y_p / 60) * 60 - 0.0000000001;
	else if (info->check == 3 || info->check == 4)
		info->distance_ay = floor(info->y_p / 60) * 60 + 60;
	info->distance_ax = info->x_p + (info->distance_ay - info->y_p) / tan((angle));
	if (info->check == 3 || info->check == 2)
		info->distance_tx = floor(info->x_p/60) * (60) - 0.0000000001;
	if (info->check == 4 || info->check == 1)
		info->distance_tx = floor(info->x_p/60) * (60) + 60;
	info->distance_ty = info->y_p - (-info->distance_tx + info->x_p) * tan((angle));
	check_intersections_hor(info, angle);
	check_intersections_vir(info, angle);
	compare_distance(info, angle);
    // pinte_point(info);
}