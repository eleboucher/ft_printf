# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 12:50:22 by elebouch          #+#    #+#              #
#    Updated: 2017/12/06 13:41:27 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS = -g3 -Wall -Werror -Wextra -I includes/ -I libft/includes

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libft
LIB = ./libft/libft.a

SRCS =\
	 ft_printf.c \
	 ft_args.c \
	 debugflags.c
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
TEMPNAME = $(addprefix $(OBJDIR), $(NAME))

all: $(NAME)

$(NAME): build $(LIB) $(OBJ)
	@ar rc $(TEMPNAME) $(OBJ)
	@libtool -static -o $(NAME) $(TEMPNAME) $(LIB) 
	@ranlib $(NAME)

build:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< 

$(LIB_DIR)/%.a:
	@make -C $(LIB_DIR)
