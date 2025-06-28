/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:31:08 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/29 00:01:09 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_start(t_data *env, int argc, char **argv);
static void	hooks(t_data *env);

// most basic main!
int	main(int argc, char **argv)
{
	t_data	env;

	check_start(&env, argc, argv);
	env_init(&env);
	hooks(&env);
	mlx_loop_hook(env.mlx, render, &env);
	render(&env);
	mlx_loop(env.mlx);
	return (0);
}

// check if first arg for set
// if julia, populate env with right data
// if wrong program call return error -> exit
static void	check_start(t_data *env, int argc, char **argv)
{
	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		env->name = argv[1];
		if (argc == 4)
		{
			env->julia_x = ft_atof(argv[2], 0);
			env->julia_y = ft_atof(argv[3], 0);
		}
		return ;
	}
	else
	{
		write(2, " Usage:\n", 7);
		write(2, "\t./fractol mandelbrot\n\t./fractol julia <real> <i>\n", 50);
		exit(1);
	}
}

// hooks ... nothing to explain here
static void	hooks(t_data *env)
{
	mlx_hook(env->win, 2, 1L << 0, key_handler, env);
	mlx_hook(env->win, 4, 1L << 2, mouse_handler, env);
	mlx_hook(env->win, 17, 1L << 2, closing, env);
}
