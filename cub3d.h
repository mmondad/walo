#ifndef CUBE_3D
#define CUBE_3D

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>


#define LEFT 97
#define RIGHT 100
#define ABOVE 119
#define LOWEST 115
#define RADIAN 0.0174533
#define SPEED 10
#define MINIMAP_SIZE 3
#define TILE_SIZE 60
#define MULT TILE_SIZE / MINIMAP_SIZE

# define VECTOR 50

typedef struct s_garbage
{
	void	*data;
	struct s_garbage *next;
}	t_garbage;

typedef	struct	s_info
{
	/*                 colors               */

	int			f_color_int;
	int			c_color_int;
	/*                 other                */
	char		*image;
	int 		endn;
	int 		bet_pxl;
	int			size_line;
	double		dir_x;
	double		dir_y;
	int			flag;
	void		*mlx;
	void		*img;
	void		*mlx_win;
	char		*save;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			size_map;
	char		**maps;
	int			ac;
	char		*map_name;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*ceiling_color;
	char		*floor_color;
	int			*c;
	int			*f;
	int			tmp;
	int			check;
	int			last_line;
	int			wight;
	char		**av;

	double			x_p;
	double			y_p;
	double		angle;
	char		player;
	double		distance_ay;
	double		distance_ax;
	///////////////////////
	double		distance_tx;
	double		distance_ty;
	///////////////////////  hit the wall
	double		intersection_x;
	double		intersection_y;
	double		hitwall_hor_y;
	double		hitwall_hor_x;
	double		hitwall_vir_y;
	double		hitwall_vir_x;
	char 		**f_color;
	char 		**c_color;
	int			w;
	int 		h;
	/*test*/
	int			move;
	double		size;
	int			var;
	t_garbage	*garbage;
	void		*barbie;
	void		*drow_barbie;
}	t_info;


#ifndef BUFFER_SIZE
# define BUFFER_SIZE	300
# endif


		/*          validators          */
double	norm(double	angle);
int		create_trgb(int t, int r, int g, int b);
int		ft_atoi_base(const char *str, int str_base);
char	*ft_itoa_base(int value, int base);
int		mouve_player(int c, t_info *info);
int 	putnum(long num);
void	compare_distance(t_info *info, double angle);
void	check_intersections_hor(t_info *info, double angle);
void	check_intersections_vir(t_info *info, double angle);
double	ft_abs(double val);
void	draw_square_t(t_info *info);
void	draw_square(t_info *info);
void	draw_vector(t_info *info);
void	design_point_haut(t_info *info);
void	my_mlx_pixel_put(t_info *info, int x, int y, int color);
void    put_pixels_as_image(t_info *info, int i, int j, long color);
void	calcul_distance(t_info *info, double angle);
void    init_window(t_info *info);
void	conditions(t_info *info, double angle);
void	init_angle(t_info *info);
void	render_player(t_info *info, int color);
int    	rendering_2d(t_info *info);
void	add_vector(t_info *info);
double	ft_abs(double val);
void	draw_vector(t_info *info);
int		is_player(char  c);
void	render_player(t_info *info, int color);
int		is_space(char c);
void	my_mlx_pixel_put(t_info *info, int x, int y, int color);
int		ft_exit();
void    init_window(t_info *info);
int		rendering_2d(t_info *info);
int		mouve_player(int c, t_info *info);
void	mouv_player_droit(t_info *info);
void    put_pixels_as_image(t_info *info, int i, int j, long color);
int		ft_strlen2(char *str);
char	*strdup_new_map(char *str, t_info *info);
char	*get_next_line(int fd, t_info *info);
char	*ft_strdup(char *str, t_info *info);
char	*ft_strjoin(char *s1, char *s2, t_info *info);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	init_info(t_info *info, int ac, char **av);
void	ft_putstr(char *str);
void	print_error(char *str);
int		ft_atoi(char *str, int i, int sign);
void    read_maps(t_info *info);
int 	check_ligne(char *maps);
int 	check_collone(char *maps);
void 	check_wall_valide(t_info *info);
void	check_nbr_player(t_info *info);
int 	check_extention_map(t_info *info);
int		strcmp_path(char *s1, char *s2, int n);
int 	is_space(char c);
char 	*set_path(char *str);
int 	ft_isdegit(char c);
int 	strlen_pro(char *str, char flag);
void    check_textures_path(t_info *info);
int 	the_biggest_line(t_info *info);
int     check_colors(t_info *info);
void	new_fnode(void *data, t_info *info);
void	free_list(t_info	*info, int i);
void	*ft_malloc(size_t size, t_info *info);
char	**ft_split(char *s, char c, t_info *info);
int		check_vergule( char *str, int   **tab, t_info *info);
int		is_map(char *str);
int 	ft_check_crct(char *str);
int 	check_valid_caractere(char c);

#endif