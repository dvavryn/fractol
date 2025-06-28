#include "libft/libft.h"
#include <mlx.h>

#define FACTOR 100
#define WIDTH 500
#define	HEIGHT 500

typedef struct t_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	int				img_line_len;
	int				img_bpp;
	int				img_endian;
	int				julia_mandel;	// julia == 1, mandel == 2, else == 0
	int				julia_val1;
	int				julia_val2;
	unsigned int	factor;
}	t_data;

void	my_pixel_put(t_data **env, int x, int y, int color)
{
	char *dst;

	dst = (*env)->img_addr + (y * (*env)->img_line_len + x * ((*env)->img_bpp / 8));
	*(unsigned int*)dst = color;
	
}

int render(t_data **env)
{
	my_pixel_put(env, 100, 100, 0x00FF0000);
	mlx_put_image_to_window((*env)->mlx, (*env)->win, (*env)->img, 0, 0);
}

void	exit_free(t_data **env, int status)
{
	if (!env || !*env)
		exit(1);
	if ((*env)->img)
		mlx_destroy_image((*env)->mlx, (*env)->img);
	if ((*env)->win)
		mlx_destroy_window((*env)->mlx, (*env)->win);
	if ((*env)->mlx)
	{
		mlx_destroy_display((*env)->mlx);
		free((*env)->mlx);
	}
	if (*env)
		free(*env);
	exit(status);
}

int	closer(t_data **env, int status)
{
	exit_free(env,0);
	return (0);
}

void	zoom_in(t_data **env)
{
	if ((*env)->factor < 100)
	{
		(*env)->factor++;
		ft_printf("zoom in\n");
	}
}

void	zoom_out(t_data **env)
{
	if ((*env)->factor > 1)
	{
		(*env)->factor--;
		ft_printf("zoom out\n");
	}
}

int	key_handler(int key, t_data **env)
{
	if (key == 65307)
		closer(env, 0);
	if (key == '=')
		zoom_in(env);
	if (key == '-')
		zoom_out(env);
	return (0);
}

void	set_fractal(t_data	**env, int argc, char **argv)
{
	if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		(*env)->julia_mandel = 2;
	if (argc == 4 && !ft_strcmp(argv[1], "julia"))
	{
		(*env)->julia_mandel = 1;
		(*env)->julia_val1 = ft_atoi(argv[2]);
		(*env)->julia_val2 = ft_atoi(argv[3]);
	}
	else
		(*env)->julia_mandel = 0;
}

void	instructions(t_data **env)
{
	write(2, "Error\n", 6);
	write(2, "Instructions\n", 14);
	exit_free(env, 1);
}

void	init_data(t_data **env, int argc, char **argv)
{
	*env = malloc(sizeof(t_data));
	if (!*env)
		exit_free(env, 1);
	// data_set_null(env);
	set_fractal(env, argc, argv);
	if ((*env)->julia_mandel == 0)
		instructions(env);
	(*env)->factor = FACTOR;
	(*env)->mlx = mlx_init();
	if (!(*env)->mlx)
		exit_free(env,1);
	(*env)->win = mlx_new_window((*env)->mlx, WIDTH, HEIGHT, "fractol");
	if (!(*env)->win)
		exit_free(env, 1);
	(*env)->img = mlx_new_image((*env)->mlx, WIDTH, HEIGHT);
	if (!(*env)->img)
		exit_free(env, 1);
	(*env)->img_addr = mlx_get_data_addr((*env)->img, &(*env)->img_bpp, &(*env)->img_line_len, &(*env)->img_endian);
	if (!(*env)->img_addr)
		exit_free(env, 1);
}

void	hooks(t_data **env)
{
	mlx_hook((*env)->win, 2, 1L << 0, key_handler, env);
	mlx_hook((*env)->win, 17, 1L << 2, closer, env);
	mlx_loop_hook((*env)->mlx, render, env);
}


int main(int argc, char **argv)
{
	t_data	*env;

	if (argc < 2)
		return (1);
	init_data(&env, argc, argv);
	hooks(&env);
	mlx_loop(env->mlx);
}





//////////////////////////////////////
//  Will I need this? I don't know! //
//////////////////////////////////////
// void	data_set_null(t_data **env) //
// {								//
// 	(*env)->mlx = NULL;				//
// 	(*env)->win = NULL;				//
// 	(*env)->img = NULL;				//
// 	(*env)->img_addr = NULL;		//
// 	(*env)->factor = FACTOR;		//
// 	(*env)->img_bpp = 0;			//
// 	(*env)->img_line_len = 0;		//
// 	(*env)->img_endian = 0;			//
// }								//
//////////////////////////////////////