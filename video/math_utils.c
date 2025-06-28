#include "fractol.h"

// [0 .. 799] -> [-2 .. +2]
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex	out;

	out.x = z1.x + z2.x;
	out.y = z1.y + z2.y;
	return (out);
}

t_complex	square_complex(t_complex z)
{
	t_complex	out;

	out.x = (z.x * z.x) - (z.y * z.y);
	out.y = 2 * z.x * z.y;
	return (out);
}

double	ft_atof(char *s)
{
	long	left_num;
	double	right_num;
	double	pow;
	int		sign;

	left_num = 0;
	right_num = 0;
	sign = 1;
	pow = 1;
	while (*s && ft_isspace(*s))
		s++;
	while (*s && (*s == '+' || *s == '-'))
	{
		if (*s++ == '-')
			sign = -sign;
	}
	while (*s != '.' && *s)
		left_num = left_num * 10 + (*s++ - '0');
	if (*s == '.' && *s)
		s++;
	while (*s)
	{
		pow /= 10;
		right_num = right_num + (*s++ - '0') * pow;
	}
	return ((left_num + right_num) * sign);
}
