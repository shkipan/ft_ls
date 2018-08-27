# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/08/27 13:43:34 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

OBJ_DIR = ./objects/
SRC_DIR = ./source/

SOURCE = alph_sorting.c \
		 fill_info.c \
		 handle.c \
		 main.c \
		 messages.c \
		 list.c \
		 options.c \
		 output.c \
		 printing.c \
		 properties.c

OBJ = $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))

HEADER = ft_ls.h

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)
	@echo "$(NAME) compiled"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)
	@echo "obj files deleted"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@echo "$(NAME) file deleted"

re: fclean all

vpath %.c $(SRC_DIR)
