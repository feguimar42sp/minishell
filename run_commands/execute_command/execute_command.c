/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:10:28 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 19:53:34 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_command(char **command_line, char **env_path)
{
	char		*temp;

	if (command_line[0][0] == '/')
	{
		temp = ft_strdup(command_line[0]);
		run_from_root(temp, command_line, env_path);
	}
	else
	{
		temp = ft_strjoin("/", command_line[0]);
		search_in_path(temp, command_line, env_path);
	}
	free(temp);
	return ;
}