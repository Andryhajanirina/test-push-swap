NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

FT_PRINTF_PATH  = ./utils/ftprintf
FT_PRINTF       = $(FT_PRINTF_PATH)/libftprintf.a

OBJ_DIR     = OBJS_FILES

SRCS        = push_swap.c \
              operations/push.c \
              operations/reverse_rotate.c \
              operations/rotate.c \
              operations/swap.c \
              parsing/check_numbers.c \
              parsing/check_duplicates.c \
              parsing/stack_init.c \
              parsing/parse_args.c \
              sorting/index_stack.c \
              sorting/radix_sort.c \
              sorting/sort_3.c \
              sorting/sort_5.c \
              sorting/sort_stack.c \
			  sorting/simple_sort.c \
			  sorting/medium_sort.c \
              utils/free_stack.c \
			  utils/ft_atoi_safe.c \
              utils/stack_utils.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# .PHONY: all clean fclean re libft
.PHONY: all clean fclean re libftprintf
RM          = rm -rf

all: $(NAME)

# compilation des .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# lien final
$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)

# compilation de libftprintf
$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH) all

# clean
clean:
	make -C $(FT_PRINTF_PATH) clean
	$(RM) $(OBJ_DIR)

fclean:
	make -C $(FT_PRINTF_PATH) fclean
	$(RM) $(OBJ_DIR) $(NAME)
	@echo "The **PUSH SWAP** $(OBJ_DIR) and $(NAME) successfully deleted."

re: fclean all