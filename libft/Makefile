# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 15:39:00 by dskrypny          #+#    #+#              #
#    Updated: 2018/08/18 17:32:09 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF_DIR = ./ft_printf
OBJ_DIR = ./objects/

SOURCE = ft_atoi.c \
			ft_bzero.c \
			ft_count_int.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_printf.c \
			ft_atoi_bin.c \
			ft_itoa_base.c \
			ft_itoa_base_printf.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memncmp.c \
			ft_memset.c \
			ft_options.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putnstr.c \
			ft_putstr_fd.c \
			ft_str_cut.c \
			ft_strcapit.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			$(PRINTF_DIR)/ft_parser.c \
			$(PRINTF_DIR)/ft_print_chr.c \
			$(PRINTF_DIR)/ft_print_hex.c \
			$(PRINTF_DIR)/ft_print_num.c \
			$(PRINTF_DIR)/ft_print_oct.c \
			$(PRINTF_DIR)/ft_print_ptr.c \
			$(PRINTF_DIR)/ft_print_str.c \
			$(PRINTF_DIR)/ft_print_str_uni.c \
			$(PRINTF_DIR)/ft_print_sym.c \
			$(PRINTF_DIR)/ft_print_uni.c \
			$(PRINTF_DIR)/ft_print_uns.c \
			$(PRINTF_DIR)/ft_printf.c \
			$(PRINTF_DIR)/init_format.c \
			$(PRINTF_DIR)/ft_check_format.c \
			$(PRINTF_DIR)/for_flags.c \
			$(PRINTF_DIR)/for_uni.c \
			$(PRINTF_DIR)/print_format.c \
			$(PRINTF_DIR)/ft_print_color.c \
			$(PRINTF_DIR)/ft_find_arg.c \
			get_next_line.c

OBJ = $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "lib created"

$(OBJ_DIR)%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	 @rm -rf $(OBJ)
	 @echo "objects deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "libft file deleted"

re: fclean all
