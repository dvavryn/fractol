/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:37:41 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/28 21:30:29 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img;

typedef struct s_data
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;

	double	escape;
	int		iterations;
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_data;

void	init_data(t_data *env, int argc, char **argv);
void	ft_exit(t_data *env);
void	free_data(t_data *env);


#endif