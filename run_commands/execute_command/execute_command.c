/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:10:28 by fernando          #+#    #+#             */
/*   Updated: 2025/01/30 14:45:14 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_lstsize(t_envp_lst *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char	**envp_lst_to_array(t_envp_lst **envp_lst)
{
	t_envp_lst	*lst;
	char		**array;
	char		*temp;
	int			lst_size;
	int			i;

	lst = *envp_lst;
	i = 0;
	lst_size = get_lstsize(*envp_lst);
	array = (char **)malloc(sizeof(char *) * lst_size + 20);
	if (!array)
	{
		write_stderr("malloc array null", 1);
		return (NULL);
	}
	while (lst)
	{
		temp = ft_strjoin(lst->var, "=");
		array[i] = ft_strjoin(temp, lst->value);
		free(temp);
		lst = lst->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	execute_command(char **command_line, char **env_path)
{
	char	**envp_array;
	char	*temp;

	envp_array = envp_lst_to_array(env_vars_list(0));
	if (command_line[0][0] == '/')
	{
		temp = ft_strdup(command_line[0]);
		run_from_root(temp, command_line, env_path, envp_array);
		free(temp);
		temp = NULL;
	}
	else
	{
		temp = ft_strjoin("/", command_line[0]);
		search_in_path(temp, command_line, env_path, envp_array);
		free(temp);
		temp = NULL;
	}
	return ;
}
