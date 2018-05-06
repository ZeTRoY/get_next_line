# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 12:28:49 by aroi              #+#    #+#              #
#    Updated: 2018/05/06 14:27:21 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADER = -I ./includes

SRC =	ft_freearr.c ft_isdigit.c ft_atoi.c ft_bzero.c ft_isalpha.c \
		ft_isalnum.c ft_isascii.c  ft_isprint.c ft_strlen.c ft_itoa.c \
		ft_lstadd.c ft_lstdelone.c ft_memdel.c ft_lstdel.c ft_lstnew.c \
		ft_lstiter.c ft_lstmap.c ft_memalloc.c ft_memccpy.c ft_memcpy.c \
		ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_putchar.c \
		ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl.c \
		ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_strncat.c ft_strcat.c \
		ft_strchr.c ft_strlcat.c ft_strclr.c ft_strncmp.c ft_strcmp.c \
		ft_strncpy.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strnequ.c \
		ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strmap.c \
		ft_strmapi.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
		ft_strlcpy.c ft_strsplittolist.c ft_itoa_base.c ft_lstaddend.c

OBJ = 	$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(HEADER) -c $(SRC)
	@ar rcs $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f libft.a

re: fclean all
