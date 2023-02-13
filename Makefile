SOURCES	= fractol.c utils.c mandelbrot.c julia.c mouse.c keyboard.c error.c 


FRAMEWORK		=	-framework OpenGL -framework AppKit

CFLAGS			=	-Wall -Werror -Wextra

LIBFTPATH		=	./libft

LIBFT			=	$(LIBFTPATH)/libft.a

MLXPATH			=	./minilibx

MLX				=	$(MLXPATH)/libmlx.a

MAKE			=	make -C

NAME			=	fractol

RM				=	rm -f

all: $(NAME)

$(LIBFT):
		$(MAKE) $(LIBFTPATH)

$(MLX):
		$(MAKE) $(MLXPATH)

$(NAME):	$(SOURCES) $(LIBFT) $(MLX)
		$(CC) $(LIBFT) $(MLX) $(SOURCES) $(FRAMEWORK) -o $(NAME)

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)
	$(MAKE) $(MLXPATH) clean
	$(MAKE) $(LIBFTPATH) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) $(LIBFTPATH) clean
	$(RM) $(MLX)

re: fclean all
