/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:51:59 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/28 20:56:29 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_name(t_data *env, int argc, char **argv)
{
	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		env->name = argv[1];
	}
	else
	{
		
		write(2, "Usage:\n", 7);
		write(2, "\t./fractol mandelbrot\n", 22);
		write(2, "\t./fractol julia <real> <i>\n", 28);
		exit(1);
	}
}

void	init_data(t_data *env, int argc, char **argv)
{
	get_name(env, argc, argv);
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_exit(env);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, env->name);
	if (!env)
		ft_exit(env);
	env->img.img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img.img)
		ft_exit(env);
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bpp,
			&env->img.ll, &env->img.endian);
}
