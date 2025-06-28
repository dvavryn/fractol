#include "fractol.h"
/* 
	z = z^2 + c
	(z initially 0)
	c is the actual point
*/

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fract)
{
	if (!ft_strcmp(fract->name, "julia"))
	{
		c->x = fract->julia_x;
		c->y = fract->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fract)
{
	t_complex z;
	t_complex c;
	int			i;
	int			color;

	z.x = (map(x, -2.0, 2.0, 0, 799.0) * fract->zoom) + fract->shift_x;
	z.y = (map(y, 2.0, -2.0, 0, 799.0) * fract->zoom) + fract->shift_y;
	mandel_vs_julia(&z, &c, fract);
	i = 0;
	while (i < fract->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fract->escape_value)
		{
			color = map(i, 0x00808080, WHITE, 0, fract->iterations_definition);
			// color = 0x00808080;
			my_pixel_put(x, y, &fract->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fract->img, BLACK);
}

int	fractal_render(t_fractal *fract)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fract);
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img, 0, 0);
	return (0);
}