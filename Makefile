NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/*.c\
	srcs/events/*.c\
	srcs/init/*.c\
	srcs/preprocess/*.c\
	srcs/utils/*.c\
	srcs/board/*.c\

INCLUDES = -I ./includes\
	-I ./graphics/libft/includes\
	-I ./graphics/gmath/includes\
	-I ./graphics/draw/includes\

LIBS = -lmlx\
	-L ./graphics/libft -lft\
	-L ./graphics/gmath -lgmath\
	-L ./graphics/draw -ldraw\

FRAMEWORKS = -framework OpenGL\
	-framework AppKit\

all : $(NAME)

$(NAME) : $(LIBS) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(FRAMEWORKS) $(SRCS) -o $(NAME)

$(LIBS) :
	$(MAKE) -C ./graphics/libft all
	$(MAKE) -C ./graphics/gmath all
	$(MAKE) -C ./graphics/draw all

clean :
	$(MAKE) -C ./graphics/libft clean
	$(MAKE) -C ./graphics/gmath clean
	$(MAKE) -C ./graphics/draw clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C ./graphics/libft fclean
	$(MAKE) -C ./graphics/gmath fclean
	$(MAKE) -C ./graphics/draw fclean
	rm -rf $(NAME)

re : fclean all