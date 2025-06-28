/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:31:06 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/28 23:59:06 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// if sth went wrong in init then free and exit error
static void	ft_error(t_data *env)
{
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	perror("Problems with malloc");
	exit(1);
}

// populate env data general
static void	data_init(t_data *env)
{
	env->escape = 20;
	env->iterations = 42;
	env->shift_x = 0;
	env->shift_y = 0;
	env->zoom = 1.0;
}

// init the environment, 
// mlx, win, img, get data adress, populate env
void	env_init(t_data *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_error(env);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, env->name);
	if (!env->win)
		ft_error(env);
	env->img.img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img.img)
		ft_error(env);
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bpp,
			&env->img.line_len, &env->img.endian);
	data_init(env);
}
