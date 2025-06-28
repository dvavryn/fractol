/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:31:04 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/29 01:00:43 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// closing and freeing the whole env
int	closing(t_data *env)
{
	mlx_destroy_image(env->mlx, env->img.img);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(0);
}

// handle keyinputs
int	key_handler(int key, t_data *env)
{
	if (key == K_ESC)
		closing(env);
	else if (key == K_UP)
		env->shift_y += 0.1 * env->zoom;
	else if (key == K_DOWN)
		env->shift_y -= 0.1 * env->zoom;
	else if (key == K_LEFT)
		env->shift_x -= 0.1 * env->zoom;
	else if (key == K_RIGHT)
		env->shift_x += 0.1 * env->zoom;
	else if (key == K_PLUS)
		env->iterations += 10;
	else if (key == K_MINUS && env->iterations > 0)
		env->iterations -= 10;
	return (0);
}

// handle mouse inputs
int	mouse_handler(int button, int x, int y, t_data *env)
{
	(void)x;
	(void)y;
	if (button == M_UP)
		env->zoom *= 0.9;
	else if (button == M_DOWN)
		env->zoom /= 0.9;
	return (0);
}
