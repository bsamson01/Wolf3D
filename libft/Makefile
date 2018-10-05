# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsamson <bsamson@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 12:51:09 by bsamson           #+#    #+#              #
#    Updated: 2018/08/24 18:50:07 by bsamson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -rf

SRC=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isalpha.c \
	ft_isascii.c line.c ft_isdigit.c ft_isprint.c  ft_itoa.c ft_memalloc.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c get_next_line.c ft_putnbr_fd.c ft_putstr.c \
	ft_putstr_fd.c ft_rem_spaces.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c \
	ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_toupper.c ft_tolower.c ft_lstadd.c ft_lstnew.c ft_cpy_to_c.c ft_str_chr.c \
	ft_cntwrd.c

OBJ=$(SRC:%.c=%.o)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
