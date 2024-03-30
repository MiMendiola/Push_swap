NAME = push_swap

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
CC = cc
RM = rm -f

LIBFTA = libft/libft.a

SRCS = $(addprefix ./src/, push_swap.c \
		movements/push.c movements/reverse_rotate.c movements/rotate.c movements/swap.c \
		stack/stack_creator.c stack/stack_properties.c stack/stack_sort.c stack/stack_utils.c stack/stack_setters.c \
		shows.c)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	@make all -sC ./libft
	@echo "$(GREEN)Compiling Libft.$(CLEAR)"
	@$(CC) $(CFLAGS) $(OBJS) -I ../push_swap.h $(LIBFTA) -o $(NAME)
	@echo "$(GREEN)Push Swap Compiled.$(CLEAR)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@make clean -sC libft
	@echo "$(RED)All Objs Deleted.$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFTA)
	@echo "$(RED)Everything Deleted.$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re
