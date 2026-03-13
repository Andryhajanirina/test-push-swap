# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 14:20:37 by mamiandr          #+#    #+#              #
#    Updated: 2026/02/09 17:06:26 by mamiandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = ft_atoi.c\
      ft_bzero.c\
      ft_calloc.c\
      ft_isalnum.c\
      ft_isalpha.c\
      ft_isascii.c\
      ft_isdigit.c\
      ft_isprint.c\
      ft_itoa.c\
      ft_memchr.c\
      ft_strdup.c\
      ft_striteri.c\
      ft_strjoin.c\
      ft_strlcat.c\
      ft_strlcpy.c\
      ft_strlen.c\
      ft_strmapi.c\
      ft_strncmp.c\
      ft_strnstr.c\
      ft_strrchr.c\
      ft_memcmp.c\
      ft_memcpy.c\
      ft_memmove.c\
      ft_memset.c\
      ft_putchar_fd.c\
      ft_putendl_fd.c\
      ft_putnbr_fd.c\
      ft_putstr_fd.c\
      ft_split.c\
      ft_strchr.c\
      ft_strtrim.c\
      ft_substr.c\
      ft_tolower.c\
      ft_toupper.c\
      ft_lstnew.c\
      ft_lstadd_front.c\
      ft_lstsize.c\
      ft_lstlast.c\
      ft_lstadd_back.c\
      ft_lstdelone.c\
      ft_lstclear.c\
      ft_lstiter.c\
      ft_lstmap.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
