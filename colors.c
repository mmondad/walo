#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


// void	prepare_texture(t_info *info, double point_depart,double x)
// {
// 	(void)x;
// 	int xtexture = (int)1.0 * info->texturewith;
// 	// xtexture -= floor((double)xtexture);
// 	// printf("xtextur = %d\n", xtexture);
// 		// exit(32);
// 	// if (info->flag == 0) // ila kan vertical
// 	// {
// 	// 	if (info->check == 3) //  ila kan droit
// 			// xtexture = info->texturewith - xtexture - 1;
// 	// }
// 	// if (info->flag == 1) // ila kan horizontal
// 	// {
// 	// 	if (info->check == 1) //  ila kan haut
// 	// 		xtexture = info->texturewith - xtexture - 1;
// 	// }
// 	double step = 1.0 * info->textureheight / info->lenght;
// 	double texpos = (point_depart - (((info->last_line + 1) * 60) / 2) + (info->lenght / 2)) *  step; // point depart dans texture 
// 	int ytexture = (int)texpos % (info->textureheight);
// 	info->color_texture = info->pointer[(info->textureheight * ytexture) + xtexture];

// }% 