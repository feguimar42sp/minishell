/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:51 by fernando          #+#    #+#             */
/*   Updated: 2024/11/02 11:36:04 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUILT_INS 4

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "./libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>
# include <signal.h>
# include "minishell_typedefs.h"
# include "memory_utils/mem_utils.h"
# include "utils/utils.h"
# include "statics/statics.h"
# include "run_commands/run_commands.h"
# include "run_commands/built-ins/built_ins.h"
# include "run_commands/execute_command/execute_command.h"
# include "run_commands/set_io/set_io.h"
# include "prompt/prompt.h"
# include "parsing/parsing.h"
# include "memory_utils/mem_utils.h"
# include "env_vars/env_vars.h"

//debug
	void print_args_lst(t_args_lst	*ptr);
	void print_split(char **s);
#endif
