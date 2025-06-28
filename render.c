/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:31:13 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/29 00:51:37 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// write color in the right data block of the address of the img
// dst = addr + offset; offset is pos of exact pixel x|y
static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

// set the right values for julia and mandelbrot
static void	man_or_jul(t_complex *z, t_complex *c, t_data *env)
{
	if (!ft_strcmp(env->name, "julia"))
	{
		c->x = env->julia_x;
		c->y = env->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

// z.x shifted by -0,5 so its more centered, zoom and arrowoffset
// set values depending on set
// put pixel greyscale if escaped
// if escaped, draw original in FRACT_COL
static void	draw(int x, int y, t_data *env)
{
	t_complex		z;
	t_complex		c;
	size_t			i;

	if (!ft_strcmp(env->name, "mandelbrot"))
		z.x = (scale(x, -2.5, 1.5) * env->zoom) + env->shift_x;
	else
		z.x = (scale(x, -2.0, 2.0)) * env->zoom + env->shift_x;
	z.y = (scale(y, 2.0, -2.0) * env->zoom) + env->shift_y;
	man_or_jul(&z, &c, env);
	i = 0;
	while (i < env->iterations)
	{
		z = add_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > env->escape)
		{
			my_pixel_put(&env->img, x, y, grayscale(i, env->iterations));
			return ;
		}
		i++;
	}
	my_pixel_put(&env->img, x, y, FRACT_COL);
}

// render, draw pixel for every point on img, put img to window after
// redo every loop_hook
int	render(t_data *env)
{
	ssize_t	x;
	ssize_t	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			draw(x, y, env);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}
