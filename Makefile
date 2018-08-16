# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/08/16 18:29:58 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

OBJ_DIR = ./objects/
SRC_DIR = ./source/

SOURCE = main.c \
		 messages.c \
		 handle.c \
		 list.c \
		 sorting.c \
		 options.c \
		 output.c \
		 properties.c

OBJ = $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))

HEADER = ft_ls.h

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)
	@echo "$(NAME) compiled"

$(OBJ_DIR)%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)
	@echo "obj files deleted"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)
	@echo "$(NAME) file deleted"

re: fclean all

vpath %.c $(SRC_DIR)
