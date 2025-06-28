/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:31:11 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/29 00:34:15 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// ratio - how far along are we in the iteration process
// shade - ratio * (max 8bit color)
// return - shift value to all 3 color channels and return 24bit int
// 129 << 16 -- 81
// so 0x818181 in hex
int	grayscale(size_t i, unsigned int iterations)
{
	double	ratio;
	int		shade;

	ratio = (double)i / (iterations - 1);
	shade = (int)round(ratio * 255.0);
	return ((shade << 16) | (shade << 8) | shade);
}

// already explained in header
double	scale(double unscaled_num, double new_min, double new_max)
{
	double	out;

	out = ((new_max - new_min) * unscaled_num / HEIGHT) + new_min;
	return (out);
}

// already explained in header
t_complex	add_complex(t_complex z1, t_complex z2)
{
	t_complex	out;

	out.x = z1.x + z2.x;
	out.y = z1.y + z2.y;
	return (out);
}

// already explained in header
t_complex	square_complex(t_complex z)
{
	t_complex	out;

	out.x = (z.x * z.x) - (z.y * z.y);
	out.y = 2 * z.x * z.y;
	return (out);
}

// already explained in header
double	ft_atof(char *s, size_t	i)
{
	long	left;
	double	right;
	double	by;
	int		sign;

	left = 0;
	right = 0;
	sign = 1;
	by = 1;
	while (s[i] && ft_isspace(s[i]))
		i++;
	while (s[i] && (s[i] == '+' || s[i] == '-'))
		if (s[i++] == '-')
			sign *= -1;
	while (s[i] && s[i] != '.')
		left = left * 10 + (*s++ - '0');
	if (s[i] && s[i] == '.')
		i++;
	while (s[i])
	{
		by /= 10;
		right = right + (s[i++] - '0') * by;
	}
	return ((left + right) * sign);
}
