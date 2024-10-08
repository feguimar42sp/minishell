/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 07:33:27 by fernando          #+#    #+#             */
/*   Updated: 2024/10/08 19:34:44 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// add new argument in function. env_vars: the environment variables
void	execute_line(char *line, t_envp_lst *env_vars)
{
	char	**parsed_line;
	int		i;

	parsed_line = ft_split(line, '|'); // if pipes exist or not, the line >
									   // will become an array of arrays
	i = 0;
	while (parsed_line[i] != NULL) // counting how many commands/words/arguments
		i++;
	*num_pipes() = i - 1; // global variable to store pipes amount
	// malloc another global with as many pipes as there are:
	*pipes() = malloc(sizeof(t_pipe) * (*num_pipes()));
	i = 0;
	while(i < *num_pipes())
	{
		pipe((*pipes())[i]);
		i++;
	}
	// pipes are being created and what's being done with them?

	i = 0;
	while (parsed_line[i] != NULL)
	{
		execute_command(parsed_line[i], i, env_vars);
		i++;
	}
	free_split(&parsed_line);
}
