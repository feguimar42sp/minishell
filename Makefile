# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:29:33 by feguimar          #+#    #+#              #
#    Updated: 2024/12/11 18:29:53 by feguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

BONUS :=

LIBFT_DIR := ./libft
LIBFT := libft/libft.a
BONUS_DIR := ./bonus

# Directories
VPATH := .
	
# Compiler
CC := cc

# Compiler flags
CFLAGS := -g -Wall -Wextra -Werror

# Linker flags
LINKER_FLAGS := -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft -lreadline

ENV_VARS_FOLDER := env_vars/expand_environment_vars.c  env_vars/ft_getenv.c \
				   env_vars/ft_strcspn.c env_vars/store_environment_vars.c env_vars/free_env_list.c \

ENV_VARS_UTILS_FOLDER := env_vars/env_vars_utils/add_env_var.c env_vars/env_vars_utils/find_previous_var_in_list.c \
	env_vars/env_vars_utils/find_var_node.c env_vars/env_vars_utils/remove_env_var.c \
	env_vars/env_vars_utils/remove_first_env_var.c env_vars/env_vars_utils/list_env_vars_ordered.c

MEMORY_UTILS_FORDER := memory_utils/add_to_mem_list.c memory_utils/free_all.c memory_utils/ft_free.c \
	memory_utils/ft_maloc.c memory_utils/print_all_mem.c memory_utils/free_args_list.c memory_utils/ft_free_split.c

PROMPT_FOLDER := prompt/get_prompt.c

STATICS_FOLDER := statics/env_vars_list.c statics/mem_list.c statics/args_list.c statics/current_exit_code.c \
	statics/prog_pid.c statics/running_loop.c

UTILS_FOLDER := utils/free_split.c utils/ft_error.c utils/ft_quote_error.c utils/clear_args_list.c \
				utils/ft_redirect_error.c utils/dump_from_file.c

PARSING_FOLDER := parsing/create_node.c parsing/split_by_quotes.c parsing/split_by_redirects.c \
	parsing/split_by_spaces.c parsing/unclosed_quotes.c parsing/ft_lexer.c \
	parsing/ft_lst_split.c parsing/ft_strcmp.c

RUN_COMMANDS_FOLDER := run_commands/run_commands.c run_commands/parse_redirect.c \
	run_commands/redirect_output.c run_commands/make_array.c run_commands/open_file.c run_commands/add_word.c \
	run_commands/run_curr_command.c run_commands/run_last_command.c

EXECUTE_COMMAND_FOLDER := run_commands/execute_command/execute_command.c run_commands/execute_command/search_in_path.c \
	run_commands/execute_command/run_from_root.c run_commands/redirect_input.c run_commands/close_files.c

BUILT_INS_FOLDER := run_commands/built-ins/fill_cmds.c run_commands/built-ins/ft_cd.c \
	run_commands/built-ins/ft_echo.c run_commands/built-ins/ft_env.c run_commands/built-ins/ft_exit_cmd.c \
	run_commands/built-ins/ft_export.c run_commands/built-ins/ft_pwd.c run_commands/built-ins/ft_unset.c \
	run_commands/built-ins/is_built_int.c run_commands/built-ins/split_env.c run_commands/built-ins/has_equal_sign.c \
	run_commands/built-ins/split_command.c
	
SET_IO_FOLDER := run_commands/set_io/input_from_file.c run_commands/set_io/input_from_pipe.c \
	run_commands/set_io/io_redirects.c run_commands/set_io/output_to_file.c run_commands/set_io/output_to_pipe.c \
	run_commands/set_io/set_last_process_io.c run_commands/set_io/set_process_io.c

SIGNALS_FOLDER := signals/handle_signals.c

SYNTAX_FOLDER := syntax/handle_syntax.c syntax/remove_outer_quotes.c

HEREDOC_FOLDER := run_commands/heredoc/expand_env_vars_heredoc.c run_commands/heredoc/expand_vars_to_string.c \
	run_commands/heredoc/ft_envlen.c run_commands/heredoc/get_var_value_heredoc.c run_commands/heredoc/heredoc_expand.c \
	run_commands/heredoc/heredoc.c run_commands/heredoc/not_end_env_var.c run_commands/heredoc/strlen_expanded.c

# Source files
SRCS := main.c $(ENV_VARS_FOLDER) $(MEMORY_UTILS_FORDER) $(PROMPT_FOLDER) $(STATICS_FOLDER) \
	$(UTILS_FOLDER) $(PARSING_FOLDER) $(RUN_COMMANDS_FOLDER) $(BUILT_INS_FOLDER) \
	$(EXECUTE_COMMAND_FOLDER) $(SET_IO_FOLDER) $(SIGNALS_FOLDER) $(SYNTAX_FOLDER) \
	$(HEREDOC_FOLDER) $(ENV_VARS_UTILS_FOLDER)

BONUS_SRCS := 

# Objects
OBJECTS := $(SRCS:.c=.o)

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

HEADERS := minishell.h

# Build target
all: lib $(NAME)

lib:
	make -C $(LIBFT_DIR) all bonus

$(NAME): $(LIBFT) $(OBJECTS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LINKER_FLAGS) -o $(NAME)

bonus: $(BONUS_OBJS)

	make -C $(BONUS_DIR)

# Run Norminette on all .c files from this project, sparing dependencies
norminette:
	@norminette $(SRCS)
	@norminette $(HEADERS)

# Clean
clean:
	@rm -f $(OBJECTS)
# 	make -C $(BONUS_DIR) clean
	@make -C $(LIBFT_DIR) clean

# Full clean
fclean:
	@make clean
	@make -C $(LIBFT_DIR) fclean
# 	make -C $(BONUS_DIR) fclean
	@rm -f $(NAME)
	

# Rebuild
re: fclean all

.PHONY: all clean fclean re
