NAME	:= fractol

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

SRCS	:= \
			basic_utils.c \
			ft_utils.c \
			handler.c \
			init.c \
			main.c \
			render.c

OBJS	:= $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L/usr/lib -lmlx -lXext -lX11 -lm 

all: $(NAME)

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

mandelbrot	: all
	@echo "Running Mandelbrot test..."
	@./$(NAME) mandelbrot

julia		: all
	@echo "Running Julia - 0.285 0.01 test..."
	@./$(NAME) julia 0.284 0.01

empty		: all
	@echo "Running empty test..."
	@./$(NAME)

toomuch		: all
	@echo "Running toomuch test..."
	@./$(NAME) julia 1 2 3

wrong		: all
	@echo "Running wrong test..."
	@./$(NAME) mandel 1 2

.PHONY	: all clean fclean re