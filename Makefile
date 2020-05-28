# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/17 16:41:55 by eenasalorin       #+#    #+#              #
#    Updated: 2020/05/28 17:16:36 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR := ./includes
SRCS_DIR := ./srcs
OBJ_DIR := ./obj

SRCS :=	cd.c \
		env.c \
		main.c \
		echo.c \
		error.c \
		quotes.c \
		sh_init.c \
		sh_exit.c \
		execute.c \
		builtin.c \
		sh_prompt.c \
		expansions.c \
		split_args.c \
		sh_move_cursor.c \
		sh_clear_screen.c \
		sh_process_input.c \
		sh_init_signal_handlers.c

OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

.PHONY : all clean fclean re

all : $(NAME)

$(OBJ_DIR):
	@/bin/mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME) : $(OBJ_DIR) $(OBJ)
	@echo "\\033[1;33mBuilding libft..\\033[0;39m"
	@make -C libft/
	@echo "\\033[1;33mBuilding 21sh..\\033[0;39m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a -ltermcap
	@echo "\\033[1;32mDONE\\033[0;39m"
	@echo "\n\\033[1;37mLaunch ./21sh\\033[0;39m"

clean :
	@echo "\\033[1;31mCleaning shell object files..\\033[0;39m"
	@rm -f $(OBJ)
	@echo "\\033[1;31mCleaning libft object files..\\033[0;39m"
	@make clean -C libft/

fclean : clean
	@echo "\n\\033[1;37mCleaning executables..\\033[0;39m"
	@rm -f $(NAME)
	@make fclean -C libft/

sh : $(OBJ_DIR) $(OBJ)
	@echo "\\033[1;33mBuilding project..\\033[0;39m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a -ltermcap
	@echo "\\033[1;32mDONE\\033[0;39m"
	@echo "\n\\033[1;37mLaunch ./21sh\\033[0;39m"
	@make clean

re : fclean all
