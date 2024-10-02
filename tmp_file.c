

/*          unused functions         */


int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}

char *ft_itoa_base(int value, int base)
{
	if (base < 2 || base > 16) return NULL;

	char *str;
	unsigned int num;
	int len = 0;
	char *base_chars = "0123456789ABCDEF";

	// Gestion des nombres négatifs pour base 10
	if (value < 0 && base == 10) {
		num = -value;
		len++;
	} else {
		num = value;
	}

	// Calcul de la longueur de la chaîne
	unsigned int temp = num;
	do {
		temp /= base;
		len++;
	} while (temp != 0);

	// Allocation de la chaîne (1 pour le '\0')
	str = malloc(len + 1);
	if (!str) return NULL;

	str[len] = '\0'; // Terminateur de chaîne

	// Remplissage de la chaîne en partant de la fin
	while (len > 0) {
		str[--len] = base_chars[num % base];
		num /= base;
	}

	// Si c'est un nombre négatif et base 10, ajout du signe
	if (value < 0 && base == 10) {
		str[0] = '-';
	}

	return str;
}

int putnum(long num)
{
	int base = 16;
	char *b = "0123456789abcdef";
	if (num <0 && base == 10)
		return write(1, "-", 1) + putnum(num*-1);
	if (num <0 && base == 16)
		return putnum((unsigned int)num);
	if (num/base==0)
		return write(1, &b[num%base], 1);
	return putnum(num/base) + putnum(num%base);
}

void	design_point_haut(t_info *info)
{
	int	x;
	int y;
	info->distance_ax = (info->distance_ax) + 60 / - tan((info->angle));
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			my_mlx_pixel_put(info, info->distance_ax + x, info->distance_ay + y - 60, 0x5f0000);
			x++;
		}
		y++;
	}
}

// void	draw_fov(t_info *info)
// {
// 	// int	a = 0;
// 	// int	b = 0;
// 	// int	line;

// 	// line = 0;
// 	// while (line < 50)
// 	// {
// 	// 	a += cos(norm(info->angle));
// 	// 	b += sin(norm(info->angle));
// 	// 	printf("angle = %f\n", norm(info->angle));
// 	// 	printf("a = %d and b = %d\n", a, b);
// 	// 	my_mlx_pixel_put(info, ((info->x_p) / 3) + a, ((info->y_p) / 3) + b, 0xffc000);
// 	// 	line++;
// 	// }
// }