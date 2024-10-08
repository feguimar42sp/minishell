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

// creating our own GETENV, because it is needed to work in the same way
// as the function getenv. the problem is that we had to store the environment
// variables inside the linked list and now the original getenv won't work.
// Ours will work with the case, in which, it will be needed to add or delete variables
char	*ft_getenv(char *var, t_envp_lst *env_vars)
{
//Received a string and the environment variables linked list.
//It searches for the string in the linked list and returns the full string.
//1. Loop through the linked list
//2. Use strncmp to check up to argument received size in the linked list.
//3.Also, look for the var variable, not the value one.
//4. return a char * of the value found in the linked list

  t_envp_lst	*temp_envp;
  char			*var_found;

  temp_envp = env_vars;

  while (env_vars)
  {
	if (ft_strncmp(var, env_vars->var, ft_strlen(var) == 0)
	{
		return (ft_strdup(env_vars->value));
	}
	env_vars = env_vars->next;
  }
  return (NULL);
}

void	execute_command(char *command, int block, t_envp_lst *env_vars)
{
	char	**parsed_command;
	char	**env_path;
	int		i;

	if (block < 0)
		return ;
	if (command == NULL)
		return ;
	//env_path = ft_split(getenv("PATH"), ':'); 
	// removed the line above and implemented the line below
	// and replaced the getenv for the ft_getenv
	env_path = ft_split(ft_getenv("PATH"), ':');
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
