#include "fractol.h"

int close_handler(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx, fract->img.img);
	mlx_destroy_window(fract->mlx, fract->win);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	exit(EXIT_SUCCESS);
}

int key_handler(int key, t_fractal *fract)
{
	if (key == 65307)
		close_handler(fract);
	else if (key == 'w')
		fract->shift_y += 0.1 * fract->zoom;
	else if (key == 's')
		fract->shift_y -= 0.1 * fract->zoom;
	else if (key == 'a')
		fract->shift_x -= 0.1 * fract->zoom;
	else if (key == 'd')
		fract->shift_x += 0.1 * fract->zoom;
	else if (key == '=')
		fract->iterations_definition +=10;
	else if (key == '-' && fract->iterations_definition > 0)
		fract->iterations_definition -=10;
	else if (key == '.')
		fract->iterations_definition +=2;
	else if (key == ',' && fract->iterations_definition > 0)
		fract->iterations_definition -=2;
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fract)
{
	if (button == 4)
		fract->zoom *= 0.9;
	else if (button == 5)
		fract->zoom /= 0.9;
	return (0);
}

int track_julia(int x, int y, t_fractal *fract)
{
	if (!ft_strcmp(fract->name, "julia"))
	{
		fract->julia_x = map(x, -2.0, 2.0, 0, WIDTH) * fract->zoom + fract->shift_x;
		fract->julia_y = map(y, 2.0, -2.0, 0, HEIGHT) * fract->zoom + fract->shift_y;
	}
	return (0);
}