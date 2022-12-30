# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 13:02:39 by antmoren          #+#    #+#              #
#    Updated: 2022/12/29 19:25:08 by antmoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap

42LIBRARY	= 	42-library
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	/bin/rm -rf
AR			= 	ar -rcs
RANLIB		= 	ranlib
INCS		= 	-I includes/

SRC_PATH 	= 	src/
OBJ_PATH 	= 	obj/


SRC			= 	main.c 				\
				check-input.c 		\
				utils.c 			\
				stack-utils.c		\
				init.c 				\
				push.c 				\
				swap.c 				\
				rotate.c 			\
				reverse_rotate.c 	\
				sort_small.c 		\
				sort_big.c 			\


SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(42LIBRARY) $(OBJS)
	@make -C $(42LIBRARY)
	@$(CC) $(CFLAGS) $(OBJS) 42-library/42lib.a -o $(NAME)
	@echo "\n 📊 push_swap compiled! ✅"

# Clean all the output files (*.o)
clean: 
	@$(RM) $(OBJ_PATH)
	@make clean -C $(42LIBRARY)
	@echo "\n 📊 push_swap executable files removed! 🗑"

# Clean all the output files (*.o) and the library file
fclean: clean
	@make fclean -C $(42LIBRARY)
	@$(RM) $(NAME)
	@echo "\n 📊 push_swap generated files removed! 🗑"

# Clean object files (*.o) and the binary file; 
re: fclean all	
	@echo "\n 🔄  ✅ Cleaned and rebuilt everything from 📊 push_swap"

.PHONY:	all bonus clean fclean re