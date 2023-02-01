# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 13:02:39 by antmoren          #+#    #+#              #
#    Updated: 2023/02/01 17:14:19 by antmoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	push_swap

42LIBRARY		= 	42-library
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CHECKER_NAME	= 	checker
RM				=	/bin/rm -rf
AR				= 	ar -rcs
RANLIB			= 	ranlib
INCS			= 	-I includes/

SRC_PATH 		= 	./src/
OBJ_PATH 		= 	./obj/

SRCS			= 	main.c 						\
					tools/check_input.c 		\
					tools/utils.c 				\
					tools/stack_utils.c			\
					tools/init.c 				\
					movements/push.c 			\
					movements/swap.c 			\
					movements/rotate.c 			\
					movements/reverse_rotate.c 	\
					sort/sort_small.c 			\
					tools/position.c 			\
					sort/sort_big.c 			\
					tools/cost.c 				\
					movements/make_move.c 		\
					tools/utils-2.c				\

SRCS_CHECKER	= 	checker.c 					\
					tools/check_input.c 		\
					tools/utils.c 				\
					tools/stack_utils.c			\
					tools/init.c 				\
					movements/push.c 			\
					movements/swap.c 			\
					movements/rotate.c 			\
					movements/reverse_rotate.c 	\
					movements/make_move.c 		\
					tools/utils-2.c				\
					tools/checker-utils.c		\

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

CHECKER_OBJS = $(addprefix $(OBJ_PATH), $(SRCS_CHECKER:.c=.o))

all: lib $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INCS) -I $(42LIBRARY) -c $< -o $@

$(OBJ_PATH): 
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)/tools
	@mkdir $(OBJ_PATH)/movements
	@mkdir $(OBJ_PATH)/sort

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) 42-library/42lib.a -o $(NAME)
	@echo "\n 📊 push_swap compiled! ✅"

bonus: lib $(CHECKER_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) 42-library/42lib.a -o $(CHECKER_NAME)
	@echo "\n 📊 push_swap bonus compiled! ✅"

lib: 
	@make -C $(42LIBRARY)

clean: 
	@$(RM) $(OBJ_PATH) $(CHECKER_OBJS)
	@make clean -C $(42LIBRARY)
	@echo "\n 📊 push_swap executable files removed! 🗑"

fclean: clean
	@make fclean -C $(42LIBRARY)
	@$(RM) $(NAME)
	@$(RM) checker
	@echo "\n 📊 push_swap generated files removed! 🗑"

re: fclean all	
	@echo "\n 🔄  ✅ Cleaned and rebuilt everything from 📊 push_swap"

.PHONY:	all bonus clean fclean re 