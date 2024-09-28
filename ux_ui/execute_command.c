/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 07:31:20 by fernando          #+#    #+#             */
/*   Updated: 2024/09/26 15:47:52 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(char *command, int block)
{
	char	**parsed_command;
	char	**env_path;
	int		i;

	if (block < 0)
		return ;
	if (command == NULL)
		return ;
	env_path = ft_split(getenv("PATH"), ':');
	parsed_command = ft_split(command, ' ');
	i = 0;
	while (parsed_command[i] != NULL)
	{
		treat_command(&(parsed_command[i]));
		i++;
	}
	i = 0;
	call_program(parsed_command[0], parsed_command, env_path, block);
	free_split(&env_path);
	free_split(&parsed_command);
}
