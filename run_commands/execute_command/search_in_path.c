/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:32:05 by fernando          #+#    #+#             */
/*   Updated: 2024/11/10 11:44:45 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	search_in_path(char *pathname, char **argv, char **envp)
{
	struct stat	fileStat;
	char		*temp;
	int			i;
	char	*a_value;

	i = 0;
	while (envp[i] != NULL)
	{
		temp = ft_strjoin(envp[i], pathname);
		if (stat(temp, &fileStat) == 0)
		{
			execve(temp, argv, envp);
			if(execve(temp, argv, envp) == -1)
			{
				a_value = strerror(errno);
				printf("strerror value: %s\n", a_value);
				printf("execve == -1\n");
				free(temp);
				exit(EXIT_FAILURE);
			}
		}
		free(temp);
		i++;
	}
	a_value = strerror(errno);
	printf("strerror value: %s\n", a_value);
	printf("execve != -1, another error was found and reached end of function\n");
	exit(EXIT_FAILURE);
}
