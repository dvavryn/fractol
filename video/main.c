#include "fractol.h"

/*
	Julia and Mandelbrot
	Infinite zoom
	Able to take command line args to disipline
		which fractal render
	Able to take command line args to shape Julia i.e xx y coordinates
	ESC closes the process with no leaks
	Same for X

*/

// 
// ./fractol mandelbrot
// ./fractol julia <real> <i>
int	main(int argc, char **argv)
{	
	t_fractal	fract;

	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		fract.name = argv[1];
		if (argc == 4)
		{
			fract.julia_x = atof(argv[2]);
			fract.julia_y = atof(argv[3]);
		}
		fractal_init(&fract);
		mlx_loop_hook(fract.mlx, fractal_render, &fract);
		fractal_render(&fract);
		mlx_loop(fract.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	}
}
