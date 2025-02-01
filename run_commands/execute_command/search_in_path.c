/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:32:47 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/01 18:29:18 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*find_path(char *pathname, char **envp)
{
	char	*temp;
	int		i;

	i = 0;
	if (pathname[1] == '.')
	{
		temp = ft_strdup(pathname + 1);
		return (temp);
	}
	while (envp[i] != NULL)
	{
		temp = ft_strjoin(envp[i], pathname);
		if (access(temp, F_OK | X_OK) == 0)
			break ;
		free(temp);
		temp = NULL;
		i++;
	}
	return (temp);
}

void	write_stderr_and_exit(char *str, int err_value)
{
	write_stderr(str, 1);
	exit(err_value);
}

void	search_in_path(char *pathname, char **argv, char **envp,
		char **real_envp_arr)
{
	struct stat	path_data;
	char		*path;

	path = find_path(pathname, envp);
	if (path == NULL)
		write_stderr_and_exit(" command not found", 127);
	if (access(path, F_OK) != 0)
		write_stderr_and_exit(" No such file or directory", 127);
	stat(path, &path_data);
	if (S_ISDIR(path_data.st_mode) != 0)
		write_stderr_and_exit(" Is a directory", 126);
	if (access(path, X_OK) != 0)
		write_stderr_and_exit(" Permission denied", 126);
	execve(path, argv, real_envp_arr);
	exit(127);
}
