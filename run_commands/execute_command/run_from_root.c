/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_from_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:29:44 by fernando          #+#    #+#             */
/*   Updated: 2024/11/12 23:09:18 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_from_root(char *pathname, char **argv, char** env_path, char **real_envp_arr)
{
	struct stat	path_data;
	
	(void)env_path;
	printf("run from root\n");
	if (pathname == NULL)
	{
		printf("if (path == NULL)\n");
		exit(127);
	}
	if (access(pathname, F_OK) != 0)
	{
		printf("if (access(temp, F_OK) != 0)\n");
		exit(127);
	}
	stat(pathname, &path_data);
	if (S_ISDIR(path_data.st_mode) != 0)
	{
		printf("if (S_ISDIR(path_data.st_mode) != 0)\n");
		exit(126);
	}
	if (access(pathname, X_OK) != 0)
	{
		printf("if (access(temp, X_OK) != 0)\n");
		exit(126);
	}
	execve(pathname, argv, real_envp_arr);
}
