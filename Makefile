# NAME		= libftprintf.a
NAME		= push_swap
cc			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

OPERATIONS_PATH	=	./operations
OPERATIONS		=	$(OPERATIONS_PATH)/

PARSING_PATH	=	./parsing
PARSING			=	$(PARSING_PATH)/

SORTING_PATH	=	./sorting
SORTING			=	$(SORTING_PATH)/

UTILS_PATH	=	./utils
UTILS			=	$(UTILS_PATH)/

OBJ_DIR     = OBJS_FILES

SRCS		+= operations/push.c \
			operations/reverse_rotate.c \
			operations/rotate.c \
			operations/swap.c

SRCS 		+= parsing/parse_args.c \
			parsing/check_numbers.c \
			parsing/check_duplicates.c \
			parsing/stack_init.c

SRCS		+= sorting/index_stack.c \
			sorting/radix_sort.c \
			sorting/sort_3.c \
			sorting/sort_5.c \
			sorting/sort_stack.c \

SRCS		+= utils/free_stack.c \
			utils/stack_utils.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
RM = rm -rf

.PHONY: all clean fclean re libft

all: $(NAME)


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(cc) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OPERATIONS):
	make -C $(OPERATIONS_PATH) all

$(PARSING):
	make -C $(PARSING_PATH) all

$(SORTING):
	make -C $(SORTING_PATH) all

$(UTILS):
	make -C $(UTILS_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean:
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJ_DIR) $(NAME)
	@echo "The **PUSH SWAP** $(OBJ_DIR) and $(NAME) successfully deleted."

re: fclean all