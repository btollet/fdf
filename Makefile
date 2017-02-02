# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 13:08:36 by benjamin          #+#    #+#              #
#    Updated: 2017/02/02 13:05:52 by benjamin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MKEX = cc -o
SRC = 	fdf.c             init.c \
		draw.c            get_file.c \
		error_free.c      event.c
FLAGS = -Wall -Wextra -Werror
OBJECT = $(SRC:.c=.o)
COMP = cc -c
NAME = fdf

all : $(NAME)

$(NAME) : $(OBJECT)
		@$(MKEX) $(NAME) $(OBJECT) -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -L libft/ -lft
		@echo "FDF compile"

$(OBJECT) :
		@make -C libft/
		@make -C minilibx_macos/
		@$(COMP) $(SRC) $(FLAGS) -I./ -I minilibx_macos/ -I libft/
		@echo "Compilation of C files succesful"

clean :
		@/bin/rm -f $(OBJECT)
		@make clean -C libft/
		@echo "Object deleted"


fclean : clean
		@/bin/rm -f $(NAME)
		@make fclean_only -C libft/
		@echo "Folder cleanup successful"

re : fclean all