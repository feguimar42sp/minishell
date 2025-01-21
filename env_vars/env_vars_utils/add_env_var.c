/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:34:55 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 21:34:28 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	LEAK FOUND WITH FREE_SPLIT() IN THIS FILE 
	leak found when commenting of the free_split() calls.

	to see leak: export HELLO=123


	DOUBLE FREE WITH FREE_SPLIT() IN THIS FILE
	to see double free: export HELLO=123
						export HELLO=456 (overwrite the 123)
*/

void	add_variable(char **elements)
{
	t_envp_lst	*ptr;

	ptr = find_var_node(elements[0]);
	if (ptr != NULL)
	{
		free(ptr->value);
		if (elements[1] != NULL)
			ptr->value = ft_strdup(elements[1]);
		else
			ptr->value = NULL;
		free_split(&elements);
		return ;
	}
	ptr = *env_vars_list();
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = malloc(sizeof(t_envp_lst));
	ptr->next->var = ft_strdup(elements[0]);
	if (elements[1] != NULL)
		ptr->next->value = ft_strdup(elements[1]);
	else
		ptr->next->value = NULL;
	ptr->next->next = NULL;
}

void	add_env_var(char *var)
{
	char		**elements;

	if (!var || *var == '=')
	{
		*current_exit_code() = 1;
		return ;
	}
	elements = ft_split(var, '=');
	if (is_valid_var(elements))
		add_variable(elements);
	else
		*current_exit_code() = 1;
	free_split(&elements);
}

int	is_valid_var(char **elements)
{
	int	i;

	if (elements == NULL)
		return (0);
	i = 0;
	while (elements[i] != NULL)
		i++;
	if (i > 2)
		return (0);
	if (!((elements[0][0] == '_') || ft_isalpha(elements[0][0])))
		return (0);
	i = 1;
	while (elements[0][i] != '\0')
	{
		if (!((elements[0][i] == '_') || ft_isalnum(elements[0][i])))
			return (0);
		i++;
	}
	return (1);
}
