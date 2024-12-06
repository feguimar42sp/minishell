/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:34:55 by fernando          #+#    #+#             */
/*   Updated: 2024/12/06 15:57:26 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_env_var(char *var)
{
	char		**elements;
	t_envp_lst	*ptr;

	elements = ft_split(var, '=');
	if (is_valid_var(elements))
	{
		ptr = find_var_node(elements[0]);
		if (ptr != NULL)
		{
			free(ptr->value);
			ptr->value = ft_strdup(elements[1]);
			free(elements);
			return ;
		}
		ptr = *env_vars_list();
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = malloc(sizeof(t_envp_lst));
		ptr->next->var = ft_strdup(elements[0]);
		ptr->next->value = ft_strdup(elements[1]);
		ptr->next->next = NULL;
	}
	free(elements);
}

int	is_valid_var(char **elements)
{
	int	i;

	if (elements == NULL)
		return (0);
	i = 0;
	while (elements[i] != NULL)
		i++;
	if (i != 2)
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
