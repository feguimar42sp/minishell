/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:05:51 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/21 09:14:19 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_envinroment_vars(char **envp)
{
	t_envp_lst	*env_vars;

	env_vars = store_envp(envp);
	*env_vars_list() = env_vars;
}

char	*init_program(void)
{
	char	*line;
	char	*prompt;

	handle_signals();
	if (isatty(STDERR_FILENO))
		reset_terminal_settings();
	*running_loop() = 0;
	prompt = get_prompt();
	line = stdin_gnl(prompt);
	free(prompt);
	return (line);
}

void	parse_line_and_create_struct(char *line)
{
	free_args_list(args_list());
	// check later args list being cleaned twice,
	// one time here and another at the end of while loop
	*args_list() = ft_lst_split(line);
	free(line);
	ft_lexer(args_list());
	handle_environment_vars_expansion(args_list());
	t_args_lst *lst = *args_list();
	int i = 0;
	while (lst != NULL)
	{
		printf("[%d] = [%s]\n", i, lst->arg);
		lst = lst->next;
		i++;
	}
	remove_outer_quotes(args_list());
}

int	main(int ac, char **av, char **envp)
{
	char		*line;

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
		parse_line_and_create_struct(line);
		if (!handle_syntax(args_list()))
		{
			write_stderr("syntax error", 1);
			continue ;
		}
		t_args_lst *lst = *args_list();
		int i = 0;
		while (lst != NULL)
		{
			printf("[%d] = [%s]\n", i, lst->arg);
			lst = lst->next;
			i++;
		}
		run_commands();
		free_args_list(args_list());
	}
	free_env_lst(env_vars_list());
	rl_clear_history();
}
