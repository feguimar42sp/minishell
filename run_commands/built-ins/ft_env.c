/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:14 by feguimar          #+#    #+#             */
/*   Updated: 2024/11/30 15:32:14 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(char **argv)
{
	char	**command;
	char	**env;
	pid_t	pid;

	env = split_env(argv);
	command = split_command(argv);
	pid = fork();
	if (pid == 0)
	{
		ft_export(env);
		*args_list() = ft_lst_split(command);
		ft_lexer(args_list());
		handle_environment_vars_expansion(args_list());
		remove_outer_quotes(args_list());
		run_commands();
		free_args_lst(args_list());
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	*current_exit_code() = status;

}
