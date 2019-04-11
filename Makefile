# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:56:40 by gmichaud          #+#    #+#              #
#    Updated: 2018/12/31 15:57:29 by mguerrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC_FLAGS = -I./includes

INC_NAME = libft.h

INC_PATH = ./includes

SRC_PATH = src

SRC_NAME = ft_memset.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstnew.c \
		ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_isblank.c\
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_putchar.c ft_isspace.c\
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
		ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
		ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
		ft_strlcat.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
		ft_lstpush_back.c ft_isupper.c ft_islower.c ft_realloc.c ft_isgraph.c \
		ft_lstlen.c get_next_line.c ft_puthexa.c ft_nbrlen.c \
		ft_putnbr_aligned.c \
		ft_printf/conv1.c \
		ft_printf/conv2.c \
		ft_printf/conv3.c \
		ft_printf/conv4.c \
		ft_printf/conv5.c \
		ft_printf/conv6.c \
		ft_printf/conv7.c \
		ft_printf/double_conv.c \
		ft_printf/fill_tab.c \
		ft_printf/ft_itoa_base.c \
		ft_printf/ft_lltoa.c \
		ft_printf/ft_max.c \
		ft_printf/ft_printf.c \
		ft_printf/long_double_conv.c \
		ft_printf/unsigned_conv.c \
		ft_printf/signed_conv.c \
		ft_printf/print_string.c \
		ft_printf/ft_pow.c \
		ft_printf/ft_abs.c \
		ft_printf/parsing_utils.c \
		ft_printf/ft_endcpy.c


CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_PATH_PRINTF = ft_printf

OBJ_NAME = $(SRC:.c=.o)

OBJ = $(subst $(SRC_PATH),$(OBJ_PATH),$(OBJ_NAME))

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

GREEN = \033[32m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@
	@echo "$(GREEN)[$(NAME)] Compilation success"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)/$(OBJ_PATH_PRINTF) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH)/$(OBJ_PATH_PRINTF) 2> /dev/null || true
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(GREEN)[$(NAME)] .o files deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)[$(NAME)] executable file deleted"

re: fclean $(NAME)
