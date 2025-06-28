#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "../libft/libft.h"
# include <mlx.h>

# define ERROR_MSG "Please enter\n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

# define BLACK		0x00000000
# define RED		0x00FF0000
# define ORANGE		0x00FF7F00
# define YELLOW		0x00FFFF00
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define INDIGO		0x004B0082
# define VIOLET		0x008B00FF
# define CYAN		0x0000FFFF
# define MAGENTA	0x00FF00FF
# define PINK		0x00FF007F
# define WHITE		0x00FFFFFF

// x real ; y i
typedef struct	s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

void	fractal_init(t_fractal *fract);
int	fractal_render(t_fractal *fract);
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

int key_handler(int key, t_fractal *fract);
int	mouse_handler(int button, int x, int y, t_fractal *fract);
int close_handler(t_fractal *fract);
int track_julia(int x, int y, t_fractal *fract);
double	ft_atof(char *s);

#endif