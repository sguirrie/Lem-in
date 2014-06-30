#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/17 20:01:40 by sguirrie          #+#    #+#              #
#    Updated: 2014/03/23 22:56:15 by sguirrie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 		lem-in

CC = 		llvm-gcc

CFLAGS = 	-Wall -Wextra -Werror -O3 -I includes/ -g

SRCDIR = 	./srcs/

OBJDIR = 	./objs/

SRC =		main.c \
			parse_utils.c \
			edges.c \
			ft_parse_init.c \
			get_next_line.c \
			init_pathfinder.c \
			utils_pathfinder.c

LIBDIR = 	./libft/

LIB =		-L $(LIBDIR) -lft

LDFLAGS = 	-I includes -g

OBJ = 		$(SRC:%.c=%.o)

OBJ_LIST =	$(addprefix $(OBJDIR), $(OBJ))

all: objsdir $(NAME)

$(NAME):  $(OBJ_LIST) includes/Lem-in.h
	@make -C $(LIBDIR)
	@echo "\033[2K\033[1;31mLIBFT is now compiled \033[1;32m√\033[0m"
	@echo "\033[2K\033[1;31mCompiling LEM-IN \033[0m"
	@$(CC) $(OBJ_LIST) -o $(NAME) $(LDFLAGS) $(LIB)
	@echo "\033[1A\033[2K\033[1;31mLEM-IN is now compiled \033[1;32m√\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[2;31mCleaning LIBFT OBJS\033[0m"
	@make -C $(LIBDIR) clean
	@echo "\033[A\033[2K\033[1;31mLIBFT OBJ cleaned \033[1;32m√\033[0m"
	@echo "\033[1;31mCleaning LEM-IN OBJS\033[0m"
	@/bin/rm -fr $(OBJ_LIST)
	@echo "\033[A\033[2K\033[1;31mLEM-IN OBJECTS cleaned \033[1;32m√\033[0m"

fclean: clean
	@echo "\033[2K\033[1;31mCleaning LIBFT.A\033[0m"
	@make -C $(LIBDIR) fclean
	@echo "\033[A\033[2K\033[1;31mLIBFT.A cleaned \033[1;32m√\033[0m"
	@echo "\033[2K\033[1;31mCleaning BINARY\033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[A\033[2K\033[1;31mBINARY cleaned \033[1;32m√\033[0m"

re: fclean all

objsdir:
	@mkdir -p $(OBJDIR)

.PHONY: all clean fclean re
