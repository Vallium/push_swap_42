# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 11:30:22 by aalliot           #+#    #+#              #
#    Updated: 2015/02/15 19:34:52 by aalliot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STATIC_LIB	= libft.a
DEBUG_LIB	= libft_debug.a
DYNAMIC_LIB	= libft.so

SRC		=	ft_bzero.c				\
			ft_memset.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_memalloc.c			\
			ft_memdel.c				\
			ft_strdup.c				\
			ft_strlen.c				\
			ft_strcpy.c				\
			ft_strncpy.c			\
			ft_strcat.c				\
			ft_strncat.c			\
			ft_strlcat.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strstr.c				\
			ft_strncmp.c			\
			ft_strnstr.c			\
			ft_strcmp.c				\
			ft_strnew.c				\
			ft_strclr.c				\
			ft_strdel.c				\
			ft_strequ.c				\
			ft_striter.c			\
			ft_striteri.c			\
			ft_strjoin.c			\
			ft_strjoin_free.c		\
			ft_strmap.c				\
			ft_strmapi.c			\
			ft_strnequ.c			\
			ft_strsplit.c			\
			ft_strsub.c				\
			ft_putstr_sub.c			\
			ft_strtrim.c			\
			ft_tolower.c			\
			ft_toupper.c			\
			ft_isprint.c			\
			ft_isascii.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isalpha.c			\
			ft_atoi.c				\
			ft_itoa.c				\
			ft_putchar.c			\
			ft_putstr.c				\
			ft_putnbr.c				\
			ft_putnbrll.c			\
			ft_putendl.c			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_lstnew.c				\
			ft_lstdelone.c			\
			ft_lstdel.c				\
			ft_lstadd.c				\
			ft_lstlen.c				\
			ft_lstiter.c			\
			ft_lstmap.c				\
			ft_lstpushback.c		\
			ft_lstsmartpushback.c	\
			ft_lstsimpledel.c		\
			ft_lstsimpledelone.c	\
			ft_lstdelnode.c			\
			ft_malloc.c				\
			ft_burger.c				\
			ft_kebab.c				\
			ft_swap.c				\
			ft_sort_bbl.c			\
			ft_sort_qck.c			\
			ft_sort_mrg.c			\
			ft_intlen.c				\
			ft_llilen.c				\
			get_next_line.c

DYNAMIC_OBJ	= $(patsubst %.c,$(DYNAMIC_DIR)/%.o,$(SRC))
STATIC_OBJ	= $(patsubst %.c,$(STATIC_DIR)/%.o,$(SRC))
DEBUG_OBJ	= $(patsubst %.c,$(DEBUG_DIR)/%.o,$(SRC))

HEAD_DIR	= includes
SRC_DIR		= src
DEBUG_DIR	= debug
STATIC_DIR	= static
DYNAMIC_DIR	= dynamic

CC			= gcc
NORMINETTE	= ~/project/colorminette/colorminette

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	FLAGS	= -Wall -Wextra -Werror -Wno-unused-result
else
	FLAGS	= -Wall -Wextra -Werror
endif
$(shell mkdir -p $(STATIC_DIR) $(DYNAMIC_DIR) $(DEBUG_DIR))

all: $(STATIC_LIB) $(DYNAMIC_LIB) $(DEBUG_LIB)

$(STATIC_LIB): $(STATIC_OBJ)
	ar rc $@ $(STATIC_OBJ)
	ranlib $@

$(DEBUG_LIB): $(DEBUG_OBJ)
	ar rc $@ $(DEBUG_OBJ)
	ranlib $@

$(DYNAMIC_LIB): $(DYNAMIC_OBJ)
	$(CC) -O3 -shared -o $@ $(DYNAMIC_OBJ)

$(STATIC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -O3 -I $(HEAD_DIR) -o $@ -c $< $(FLAGS)

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -I $(HEAD_DIR) -o $@ -c $< $(FLAGS) -g

$(DYNAMIC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -O3 -fPIC -I $(HEAD_DIR) -o $@ -c $< $(FLAGS)

.PHONY: clean fclean re norme

norme:
	@$(NORMINETTE) $(SRC_DIR)/ $(HEAD_DIR)/

clean:
	@rm -f $(STATIC_OBJ) $(DYNAMIC_OBJ) $(DEBUG_OBJ)

fclean: clean
	@rm -f $(STATIC_LIB) $(DYNAMIC_LIB) $(DEBUG_LIB)

re: fclean
	make

reall: all
