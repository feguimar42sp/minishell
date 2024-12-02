/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_var_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:34:55 by fernando          #+#    #+#             */
/*   Updated: 2024/12/01 23:09:20 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_envp_lst	*find_var_node(char *name)
{
	t_envp_lst	*ptr;

	if ((*env_vars_list()) == NULL)
		return (NULL);
	ptr = *env_vars_list();
	while (ptr != NULL)
	{
		if (ft_strncmp(name, ptr->var, ft_strlen(name) + 1) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
