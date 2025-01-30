/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:05:51 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/30 19:55:56 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_envinroment_vars(char **envp)
{
	t_envp_lst	*env_vars;

	env_vars = store_envp(envp);
	*env_vars_list(0) = env_vars;
}

char	*init_program(void)
{
	char	*line;
	char	*prompt;

	handle_signals();
	if (isatty(STDIN_FILENO))
		reset_terminal_settings();
	*running_loop() = 0;
	*child_process() = 0;
	prompt = get_prompt();
	line = stdin_gnl(prompt);
	free(prompt);
	return (line);
}

int	validate_args_list(void)
{
	t_args_lst	*temp;

	while ((*args_list()) && (ft_strcmp((*args_list())->arg, "") == 0))
	{
		temp = (*args_list());
		*args_list() = (*args_list())->next;
		free(temp);
	}
	if (*args_list() == NULL)
		return (0);
	if (!handle_syntax(args_list()))
	{
		write_stderr("syntax error", 1);
		return (0);
	}
	return (1);
}

int	parse_line_and_create_struct(char *line)
{
	free_args_list(args_list());
	*args_list() = ft_lst_split(line);
	if (*args_list() == NULL)
		return (0);
	free(line);
	ft_lexer(args_list());
	handle_environment_vars_expansion(args_list());
	if (!validate_args_list())
		return (0);
	remove_outer_quotes(args_list());
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char	*line;

	if (ac > 1)
		script_files(av);
	line = NULL;
	init_envinroment_vars(envp);
	while (1)
	{
		line = init_program();
		if (!line)
			break ;
		add_history(line);
		if (!parse_line_and_create_struct(line))
			continue ;
		run_commands(*args_list(), NULL);
		free_args_list(args_list());
	}
	close_all();
	free_env_lst(env_vars_list(0));
	rl_clear_history();
}

// ls -R /
