# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 22:30:00 by kyanagis          #+#    #+#              #
#    Updated: 2025/09/02 01:42:42 by kyanagis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

AR          = ar rcs
RM          = rm -f

SRC         = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
              ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
              ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
              ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
              ft_atoi.c ft_calloc.c ft_strdup.c \
              ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
              ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
              ft_putendl_fd.c ft_putnbr_fd.c ft_atof.c ft_strncmp.c ft_strcmp.c \
              ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_isspace.c get_next_line.c

OBJ         = $(SRC:.c=.o)

BONUS_SRC   = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
              ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
              ft_lstmap.c

BONUS_OBJ   = $(BONUS_SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
