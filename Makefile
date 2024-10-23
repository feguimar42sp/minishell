# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernando <fernando@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:29:33 by feguimar          #+#    #+#              #
#    Updated: 2024/10/23 15:52:07 by fernando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

BONUS :=

LIBFT_DIR := ./libft
BONUS_DIR := ./bonus

# Directories
VPATH := .
	
# Compiler
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Linker flags
LINKER_FLAGS := -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft -lreadline

ENV_VARS_FOLDER := env_vars/env_vars.c

MEMORY_UTILS_FORDER := memory_utils/add_to_mem_list.c memory_utils/free_all.c memory_utils/ft_free.c \
	memory_utils/ft_maloc.c memory_utils/print_all_mem.c

PROMPT_FOLDER := prompt/get_prompt.c

STATICS_FOLDER := statics/env_vars_list.c statics/mem_list.c statics/args_list.c

UTILS_FOLDER := utils/free_split.c utils/ft_error.c

PARSING_FOLDER := parsing/create_node.c parsing/split_by_quotes.c parsing/split_by_redirects.c \
	parsing/split_by_spaces.c parsing/unclosed_quotes.c parsing/ft_lexer.c \
	parsing/ft_lst_split.c parsing/ft_strcmp.c

# Source files
SRCS := main.c $(ENV_VARS_FOLDER) $(MEMORY_UTILS_FORDER) $(PROMPT_FOLDER) $(STATICS_FOLDER) $(UTILS_FOLDER) $(PARSING_FOLDER)

BONUS_SRCS := 

# Objects
OBJECTS := $(SRCS:.c=.o)

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

HEADERS := minishell.h

# Build target
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) $(LINKER_FLAGS) -o $(NAME)
	
LIBFT := libft/libft.a

$(LIBFT): libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
	libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
	libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c \
	libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstmap.c libft/ft_lstnew.c \
	libft/ft_lstsize.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
	libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
	libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c \
	libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c \
	libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
	libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
	libft/libft.h libft/Makefile
	
	make -C $(LIBFT_DIR)

bonus: $(BONUS_OBJS)

	make -C $(BONUS_DIR)

# Run Norminette on all .c files from this project, sparing dependencies
norminette:
	norminette $(SRCS)
	norminette $(HEADERS)

# Clean
clean:
	rm -f $(OBJECTS)
# 	make -C $(BONUS_DIR) clean
	make -C $(LIBFT_DIR) clean

# Full clean
fclean:
	make clean
	make -C $(LIBFT_DIR) fclean
# 	make -C $(BONUS_DIR) fclean
	rm -f $(NAME)
	

# Rebuild
re: fclean all

.PHONY: all clean fclean re
