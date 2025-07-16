# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 14:55:34 by jhor              #+#    #+#              #
#    Updated: 2025/04/18 14:55:34 by jhor             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = pipex
RM = rm -f

LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = src/cmd1.c src/pipex_utils.c pipex.c src/cmd_arg.c src/pipex_utils2.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -Ipipex.h -Ilibft/libft.h $(OBJ) $(LIBFT) -o $@

all: $(NAME)



%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	make clean -C $(LIBFT_DIR)

re: fclean $(NAME)

.PHONY: all clean fclean re