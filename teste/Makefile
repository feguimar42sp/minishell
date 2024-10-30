# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernando <fernando@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:29:33 by feguimar          #+#    #+#              #
#    Updated: 2024/10/30 16:16:07 by fernando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

BONUS :=

LIBFT_DIR := ../libft
BONUS_DIR := ../bonus

# Directories
VPATH := .
	
# Compiler
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Linker flags
LINKER_FLAGS := -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft -lreadline

PROJ_ROOT := ../

ENV_VARS_FOLDER := $(PROJ_ROOT)env_vars/env_vars.c

MEMORY_UTILS_FORDER := $(PROJ_ROOT)memory_utils/add_to_mem_list.c $(PROJ_ROOT)memory_utils/free_all.c $(PROJ_ROOT)memory_utils/ft_free.c \
	$(PROJ_ROOT)memory_utils/ft_maloc.c $(PROJ_ROOT)memory_utils/print_all_mem.c

PROMPT_FOLDER := $(PROJ_ROOT)prompt/get_prompt.c

STATICS_FOLDER := $(PROJ_ROOT)statics/env_vars_list.c $(PROJ_ROOT)statics/mem_list.c $(PROJ_ROOT)statics/args_list.c

UTILS_FOLDER := $(PROJ_ROOT)utils/free_split.c $(PROJ_ROOT)utils/ft_error.c $(PROJ_ROOT)utils/ft_quote_error.c $(PROJ_ROOT)utils/clear_args_list.c \
	$(PROJ_ROOT)utils/ft_redirect_error.c

PARSING_FOLDER := $(PROJ_ROOT)parsing/create_node.c $(PROJ_ROOT)parsing/split_by_quotes.c $(PROJ_ROOT)parsing/split_by_redirects.c \
	$(PROJ_ROOT)parsing/split_by_spaces.c $(PROJ_ROOT)parsing/unclosed_quotes.c $(PROJ_ROOT)parsing/ft_lexer.c \
	$(PROJ_ROOT)parsing/ft_lst_split.c $(PROJ_ROOT)parsing/ft_strcmp.c

RUN_COMMANDS_FORDER := $(PROJ_ROOT)run_commands/run_commands.c $(PROJ_ROOT)run_commands/parse_redirect.c $(PROJ_ROOT)run_commands/io_redirects.c \
	$(PROJ_ROOT)run_commands/redirect_output.c $(PROJ_ROOT)run_commands/make_array.c $(PROJ_ROOT)run_commands/open_file.c $(PROJ_ROOT)run_commands/add_word.c \
	$(PROJ_ROOT)run_commands/run_curr_command.c $(PROJ_ROOT)run_commands/set_process_io.c $(PROJ_ROOT)run_commands/run_last_command.c \
	$(PROJ_ROOT)run_commands/set_last_process_io.c

EXECUTE_COMMAND_FOLDER := $(PROJ_ROOT)run_commands/execute_command/execute_command.c $(PROJ_ROOT)run_commands/execute_command/search_in_path.c \
	$(PROJ_ROOT)run_commands/execute_command/run_from_root.c

BUILT_INS_FOLDER := $(PROJ_ROOT)run_commands/built-ins/fill_cmds.c $(PROJ_ROOT)run_commands/built-ins/ft_cd.c $(PROJ_ROOT)run_commands/built-ins/ft_exit_cmd.c \
	$(PROJ_ROOT)run_commands/built-ins/ft_export.c $(PROJ_ROOT)run_commands/built-ins/ft_pwd.c $(PROJ_ROOT)run_commands/built-ins/is_built_int.c

# Source files
SRCS := main.c $(ENV_VARS_FOLDER) $(MEMORY_UTILS_FORDER) $(PROMPT_FOLDER) $(STATICS_FOLDER) \
	$(UTILS_FOLDER) $(PARSING_FOLDER) $(RUN_COMMANDS_FORDER) $(BUILT_INS_FOLDER) $(EXECUTE_COMMAND_FOLDER)

BONUS_SRCS := 

# Objects
OBJECTS := $(SRCS:.c=.o)

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

HEADERS := ../minishell.h

# Build target
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) $(LINKER_FLAGS) -o $(NAME)
	
LIBFT := $(PROJ_ROOT)libft/libft.a

$(LIBFT): $(PROJ_ROOT)libft/ft_atoi.c $(PROJ_ROOT)libft/ft_bzero.c $(PROJ_ROOT)libft/ft_calloc.c \
	$(PROJ_ROOT)libft/ft_isalnum.c $(PROJ_ROOT)libft/ft_isalpha.c $(PROJ_ROOT)libft/ft_isascii.c $(PROJ_ROOT)libft/ft_isdigit.c \
	$(PROJ_ROOT)libft/ft_isprint.c $(PROJ_ROOT)libft/ft_itoa.c $(PROJ_ROOT)libft/ft_lstadd_back.c \
	$(PROJ_ROOT)libft/ft_lstadd_front.c $(PROJ_ROOT)libft/ft_lstclear.c $(PROJ_ROOT)libft/ft_lstdelone.c \
	$(PROJ_ROOT)libft/ft_lstiter.c $(PROJ_ROOT)libft/ft_lstlast.c $(PROJ_ROOT)libft/ft_lstmap.c $(PROJ_ROOT)libft/ft_lstnew.c \
	$(PROJ_ROOT)libft/ft_lstsize.c $(PROJ_ROOT)libft/ft_memchr.c $(PROJ_ROOT)libft/ft_memcmp.c $(PROJ_ROOT)libft/ft_memcpy.c \
	$(PROJ_ROOT)libft/ft_memmove.c $(PROJ_ROOT)libft/ft_memset.c $(PROJ_ROOT)libft/ft_putchar_fd.c \
	$(PROJ_ROOT)libft/ft_putendl_fd.c $(PROJ_ROOT)libft/ft_putnbr_fd.c $(PROJ_ROOT)libft/ft_putstr_fd.c \
	$(PROJ_ROOT)libft/ft_split.c $(PROJ_ROOT)libft/ft_strchr.c $(PROJ_ROOT)libft/ft_strdup.c $(PROJ_ROOT)libft/ft_striteri.c \
	$(PROJ_ROOT)libft/ft_strjoin.c $(PROJ_ROOT)libft/ft_strlcat.c $(PROJ_ROOT)libft/ft_strlcpy.c $(PROJ_ROOT)libft/ft_strlen.c \
	$(PROJ_ROOT)libft/ft_strmapi.c $(PROJ_ROOT)libft/ft_strncmp.c $(PROJ_ROOT)libft/ft_strnstr.c $(PROJ_ROOT)libft/ft_strrchr.c \
	$(PROJ_ROOT)libft/ft_strtrim.c $(PROJ_ROOT)libft/ft_substr.c $(PROJ_ROOT)libft/ft_tolower.c $(PROJ_ROOT)libft/ft_toupper.c \
	$(PROJ_ROOT)libft/$(PROJ_ROOT)libft.h $(PROJ_ROOT)libft/Makefile
	
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
