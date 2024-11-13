/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:10:28 by fernando          #+#    #+#             */
/*   Updated: 2024/11/12 23:08:53 by sabrifer         ###   ########.fr       */
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
	int			lst_size;
	int			i;

	lst = *envp_lst;
	i = 0;
	lst_size = get_lstsize(*envp_lst);
	array = (char **)malloc(sizeof(char *) * lst_size + 1);
	if (!array)
	{
		printf("malloc array null\n");
		return (NULL);
	}
	while (lst)
	{
		array[i] = ft_strjoin(ft_strjoin(lst->var, "="), lst->value);
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

	envp_array = envp_lst_to_array(env_vars_list());
	if (command_line[0][0] == '/')
	{
		temp = ft_strdup(command_line[0]);
		run_from_root(temp, command_line, env_path, envp_array);
	}
	else
	{
		temp = ft_strjoin("/", command_line[0]);
		search_in_path(temp, command_line, env_path, envp_array);
	}
	free(temp);
	return ;
}
