#include "fractol.h"

static void	malloc_error(int status)
{
	perror("Problems with malloc");
	exit(status);
}

static void	data_init(t_fractal *fract)
{
	fract->escape_value = 20;
	fract->iterations_definition = 42;
	fract->shift_x = 0;
	fract->shift_y = 0;
	fract->zoom = 1.0;
}

static void	events_init(t_fractal *fract)
{
	mlx_hook(fract->win, 2, 1L << 0, key_handler, fract);
	mlx_hook(fract->win, 4, 1L << 2, mouse_handler, fract);
	mlx_hook(fract->win, 17, 1L << 2, close_handler, fract);
	mlx_hook(fract->win, 6, 1L << 6, track_julia, fract);
}

void	fractal_init(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		malloc_error(1);
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (!fract->win)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		malloc_error(2);
	}
	fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		malloc_error(3);
	}
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bpp, &fract->img.line_len, &fract->img.endian);
	data_init(fract);
	events_init(fract);
}