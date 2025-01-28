/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_from_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:29:44 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 15:11:29 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_from_root(char *pathname, char **argv, char **env_path,
		char **real_envp_arr)
{
	struct stat	path_data;

	(void)env_path;
	if (pathname == NULL)
		write_stderr_and_exit(" command not found", 127);
	if (access(pathname, F_OK) != 0)
		write_stderr(" No such file or directory", 127);
	stat(pathname, &path_data);
	if (S_ISDIR(path_data.st_mode) != 0)
		write_stderr_and_exit(" Is a directory", 126);
	if (access(pathname, X_OK) != 0)
		write_stderr_and_exit(" Permission denied", 126);
	execve(pathname, argv, real_envp_arr);
	exit(127);
}
