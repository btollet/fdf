# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 13:08:36 by benjamin          #+#    #+#              #
#    Updated: 2016/12/25 12:52:29 by benjamin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MKEX = cc -o
SRC = 	fdf.c \
		draw.c
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
		@echo "Object deleted"


fclean : clean
		@/bin/rm -f $(NAME)
		@echo "Folder cleanup successful"

re : fclean all