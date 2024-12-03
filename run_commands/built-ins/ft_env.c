/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:14 by feguimar          #+#    #+#             */
/*   Updated: 2024/12/03 01:49:44 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(char **argv)
{
	char	*command;
	char	**env;
	pid_t	pid;
	int		status;

	env = split_env(argv);
	command = split_command(argv);
	clear_args_list(args_list());
	*args_list() = ft_lst_split(command);
	pid = fork();
	if (pid == 0)
	{
		ft_export(env);
		free_split(&env);
		free(command);
		ft_lexer(args_list());
		handle_environment_vars_expansion(args_list());
		remove_outer_quotes(args_list());
		run_commands();
		free_args_lst(args_list());
		exit(*current_exit_code());
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	*current_exit_code() = status;
}
