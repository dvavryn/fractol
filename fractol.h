/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:31:01 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/29 00:58:48 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

// # include "libft/libft.h"
# include <mlx.h>

// window size
# define WIDTH 800
# define HEIGHT 800

// keys ... didnt want to use <X11/keysym.h>
# define K_ESC 0xff1b
# define K_UP 0xff52
# define K_DOWN 0xff54
# define K_LEFT 0xff51
# define K_RIGHT 0xff53
# define K_PLUS '='
# define K_MINUS '-'

// mouse buttons .. scrollwheels
# define M_UP 4
# define M_DOWN 5

// just black for now
// felt cute today
// maybe change later
# define FRACT_COL 0x0

/* 
	t_complex
	home of the read and imaginary coordinate
	of a complex number
	x real
	y imaginary
*/
typedef struct s_complex
{
	double	x;
	double	y;

}	t_complex;

/* 
	t_img
	home of the data required for an image
	bpp - bytes per pixel
*/
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

}	t_img;

/* 
	t_data
	home of MLX and some data required for
	img calculations
*/
typedef struct s_data
{
	char			*name;
	void			*mlx;
	void			*win;
	t_img			img;

	double			escape;
	unsigned int	iterations;

	double			shift_x;
	double			shift_y;
	double			zoom;

	double			julia_x;
	double			julia_y;

}	t_data;

// intit.c
// intialising	tdata env; [pass &env]
void			env_init(t_data *env);

// render.c
// render and put img to window
int				render(t_data *env);

// events.c
// handle closing
int				closing(t_data *env);
// handle keypresses
// K_UP, K_DOWN, K_LEFT, K_RIGHT, K_PLUS, K_MINUS, K_ESC
int				key_handler(int key, t_data *env);
// handle scrolling
// M_UP, M_DOWN, x and y needed for not segfaulting (void)x; (void)y;
int				mouse_handler(int button, int x, int y, t_data *env);

// utils.c
// scale coordinate system 2|2 to windowsize(HEIGHT, WIDTH)
// WIDTH >= HEIGHT !!
// based on HEIGHT!!
double			scale(double unscaled_num, double new_min, double new_max);
// basic argument to float
double			ft_atof(char *s, size_t i);
// add 2 complex numbers, z3 = z1 + z2
// z3.x = z1.x + z2.x
// z3.y = z1.y + z2.y
t_complex		add_complex(t_complex z1, t_complex z2);
// square a complex number, z2 = z1^2 || z2 = z1 * z1
// z2.x = (z1.x * z1.x) - (z1.y * z1.y);
// z2.y = 2 * z1.x * z1.y
t_complex		square_complex(t_complex z);
// math.h req! -- round()
// gets a grey colorvalue based on current iteration to max_iteration
int				grayscale(size_t i, unsigned int iterations);
// ft_utils.c
int				ft_isspace(int c);
int				ft_strcmp(const char *s1, const char *s2);

#endif