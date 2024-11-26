/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:00:57 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/02 20:08:12 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv(char *variable)
{
	t_envp_lst	**lst;
	t_envp_lst	*current;

	lst = env_vars_list();
	current = *lst;
	while (current)
	{
		if (ft_strcmp(variable, current->var) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
