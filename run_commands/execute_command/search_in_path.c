/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:32:05 by fernando          #+#    #+#             */
/*   Updated: 2024/11/07 18:59:51 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	search_in_path(char *pathname, char **argv, char **envp)
{
	struct stat	fileStat;
	char		*temp;
	int			i;

	i = 0;
	while (envp[i] != NULL)
	{
		temp = ft_strjoin(envp[i], pathname);
		if (stat(temp, &fileStat) == 0)
		{
			if(execve(temp, argv, envp) == -1)
				exit(EXIT_FAILURE);
		}
		free(temp);
		i++;
	}
	return ;
}
