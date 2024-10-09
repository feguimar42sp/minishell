/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:47:17 by sabrifer          #+#    #+#             */
/*   Updated: 2024/10/07 20:47:37 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
// list is only here for reference
typedef struct s_envp_lst
{
  char			*var;
  char			*value;
  s_envp_lst	*next;
}				t_envp_lst;
*/

// function that returns the index of where the function strchr finds
// the char being searched.
int	find_pos_strchr(char *str, char c)
{
	char *strchr_return ;
	strchr_return = ft_strchr(str, c);
	// find position of first ocurrence of char
	if (strchr_return != NULL)
		return (strchr_return - str);
	return (-1); // -1 because it can return any number starting from position 0
}

void	add_to_lst(t_envp_lst **env_var, char *env)
{
	t_envp_lst	*temp;
	t_envp_lst	*new_node;

	temp = *env_var;
	new_node = (t_envp_lst *)malloc(sizeof(t_envp_lst));
	if (new_node == NULL)
	{
		printf("new_node == null\n");
		return ;
	}
	// for reference: char	*ft_substr(char const *s, size_t start, size_t len)
	// first str == pos 0 + return value - 1 from function find_pos_strchr
	new_node->var = ft_substr(env, 0, find_pos_strchr(env, '='));
	//printf("new_node->var = %s\n", new_node->var);
	// second str == retun value + 1 from function find_pos_strchr until strlen
	new_node->value = ft_substr(env, find_pos_strchr(env, '=') + 1, ft_strlen(env));
	//printf("new_node->value = %s\n", new_node->value);
	new_node->next = NULL;
	if (temp == NULL)
	{
		*env_var = new_node;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

// function to store the envps for later user.
t_envp_lst	*store_envp(char **envp)
{
	int			i;
	t_envp_lst	*env_var;

	i = 0;
	// malloc for the env_var = initializing the list
	env_var = NULL;
	while (envp[i])
	{
	  add_to_lst(&env_var, envp[i]);
	  i++;
	}
	return (env_var);
}
/*
int	main(int argc, char **argv, char **envp)
{
  t_envp_lst	*lst_env_args;

  lst_env_args = store_envp(envp);
	int i = 0;
	while (lst_env_args)
	{
		//printf("[node %d]\t[var = %s]\t[value = %s]\n", i, lst_env_args->var, lst_env_args->value);
		lst_env_args = lst_env_args->next;
		i++;
	}

  return (0);
}*/
