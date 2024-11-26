/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:05:51 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/26 12:04:07 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char		*line;
	char		*prompt;
	t_envp_lst	*env_vars;

	(void)ac;
	(void)av;
	line = NULL;
	env_vars = store_envp(envp);
	*env_vars_list() = env_vars;
	handle_signals();
	while (1)
	{
		prompt = get_prompt();
		line = readline(prompt);
		free(prompt);
		if (line)
		{
			add_history(line);
			clear_args_list(args_list());
			*args_list() = ft_lst_split(line);
			free(line);
			ft_lexer(args_list());
			handle_environment_vars_expansion(args_list());
			run_commands();
			free_args_lst(args_list());
		}
		else
			break ; // deals with ctrl + d (sigquit)
	}
	free_env_lst(env_vars_list());
	rl_clear_history();
}
