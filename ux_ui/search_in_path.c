/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:32:05 by fernando          #+#    #+#             */
/*   Updated: 2024/09/26 17:03:08 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**environ;

int	search_in_path(char *pathname, char **argv, char **envp, int block)
{
	struct stat	fileStat;
	char		*temp;
	int			i;
	int			ret;
	pid_t		pid;

	i = 0;
	ret = 0;
	while (envp[i] != NULL)
	{
		temp = ft_strjoin(envp[i], pathname); // pathname - command
		if (stat(temp, &fileStat) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				to_pipe(block);
				ret = execve(temp, argv, environ);
			}
			wait(NULL); // to check
			close_pipe(block);
			free(temp);
			break ;
		}
		free(temp);
		i++;
	}
	return (ret);
}

int	run_from_root(char *pathname, char **argv, int block)
{
	struct stat	fileStat;
	char		*temp;
	int			ret;
	pid_t		pid;

	ret = 0;
	temp = ft_strdup(pathname);
	if (stat(temp, &fileStat) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			to_pipe(block);
			ret = execve(temp, argv, environ);
		}
	}
	wait(NULL);
	close_pipe(block);
	free(temp);
	return (ret);
}
