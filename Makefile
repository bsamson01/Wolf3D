NAME = wolf3D
COMP = gcc -Wall -Wextra -Werror
SRC = end_game.c menu.c make_mini.c keys.c render.c main.c map_get.c get_color.c initialize.c fill_image.c
OBJ = $(SRC:%.c=%.o)
HEAD = wolf.h
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/


all: $(NAME)

$(NAME) :
	@make -C libft/
	@echo "Libft Successfully compiled"
	@$(COMP) -I $(PATH_INC) -c $(SRC)
	@echo "Source files succesfully compiled"
	@$(COMP) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "Project Successfully Compiled"
clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
