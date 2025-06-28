/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:40:24 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/28 21:28:46 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	closing(t_data *env)
{
	free_data(env);
	exit(0);
}

int key_handler(int key, t_data *env)
{
	if (key == 65307)
		closing(env);
	else if (key = 'w')
		;
	else if (key = 's')
		;
	else if (key = 'a')
		;
	else if (key = 'd')
		;
	else if (key = '-')
		;
	else if (key = '=')
		;
	return (0);
}

int render(t_data *env)
{
	
}

int main(int argc, char **argv)
{
	t_data	env;

	init_data(&env, argc, argv);
	mlx_hook(env.win, 17, 1L << 2, closing, &env);
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	mlx_loop_hook(env.mlx, render, &env);
	mlx_loop(env.mlx);
}