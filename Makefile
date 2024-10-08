# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernando <fernando@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:29:33 by feguimar          #+#    #+#              #
#    Updated: 2024/10/04 19:16:17 by fernando         ###   ########.fr        #
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

# Source files
SRCS := main.c utils/ft_error.c memory_utils/free_all.c ux_ui/get_prompt.c ux_ui/execute_command.c \
	ux_ui/execute_line.c utils/call_program.c ux_ui/search_in_path.c utils/free_split.c \
	ux_ui/is_command.c ux_ui/change_dir.c pipe_proc/to_pipe.c \
	treat_command/treat_command.c treat_command/check_double_quote.c \
	treat_command/check_single_quote.c treat_command/expand_env_var.c statics/pipes.c \
	memory_utils/ft_malloc.c statics/mem_list.c memory_utils/add_to_mem_list.c \
	memory_utils/ft_free.c env_vars.c

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
