cc main.c init.c math_utils.c render.c events.c -L../libft/ -lft -L/usr/lib -lmlx -lXext -lX11 -lm -lz -Imlx -o fractol -g
# ./fractol mandelbrot
./fractol julia "0.0" "0.8"