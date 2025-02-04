/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_from_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:29:44 by fernando          #+#    #+#             */
/*   Updated: 2025/02/04 15:47:30 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_from_root(char *command, char **cmd_flags, char **envp_arr)
{
	struct stat	path_data;

	if ((command == NULL) || (access(command, F_OK) != 0))
	{
		close_all();
		free_env_lst(env_vars_list(0));
		free_split(&envp_arr);
		if (command == NULL)
			write_stderr_and_exit(" command not found", 127, &cmd_flags,
				&command);
		if (access(command, F_OK) != 0)
			write_stderr_and_exit(" No such file or directory", 127, &cmd_flags,
				&command);
	}
	stat(command, &path_data);
	if ((S_ISDIR(path_data.st_mode) != 0) || (access(command, X_OK) != 0))
	{
		close_all();
		free_env_lst(env_vars_list(0));
		free_split(&envp_arr);
		if (S_ISDIR(path_data.st_mode) != 0)
			write_stderr_and_exit(" Is a directory", 126, &cmd_flags, &command);
		if (access(command, X_OK) != 0)
			write_stderr_and_exit(" Permission denied", 126, &cmd_flags,
				&command);
	}
	execve(command, cmd_flags, envp_arr);
	free_env_lst(env_vars_list(0));
	close_all();
	exit(127);
}
