/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 07:33:27 by fernando          #+#    #+#             */
/*   Updated: 2024/09/26 16:50:11 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// add new argument in function. env_vars: the environment variables
void	execute_line(char *line, t_envp_lst *env_vars)
{
	char	**parsed_line;
	int		i;

	parsed_line = ft_split(line, '|');
	i = 0;
	while (parsed_line[i] != NULL)
		i++;
	*num_pipes() = i - 1;
	*pipes() = malloc(sizeof(t_pipe) * (*num_pipes()));
	i = 0;
	while(i < *num_pipes())
	{
		pipe((*pipes())[i]);
		i++;
	}
	i = 0;
	while (parsed_line[i] != NULL)
	{
		execute_command(parsed_line[i], i, env_vars);
		i++;
	}
	free_split(&parsed_line);
}
