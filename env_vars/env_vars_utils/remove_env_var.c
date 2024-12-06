/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:37:08 by feguimar          #+#    #+#             */
/*   Updated: 2024/12/06 15:56:54 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	remove_env_var(char *name)
{
	t_envp_lst	*var_to_remove;
	t_envp_lst	*prev_var_on_list;

	if (name == NULL)
		return ;
	prev_var_on_list = NULL;
	var_to_remove = find_var_node(name);
	if (var_to_remove == NULL)
	{
		printf("No such variable found\n");
		return ;
	}
	prev_var_on_list = find_previous_var_in_list(name);
	prev_var_on_list->next = var_to_remove->next;
	free(var_to_remove->var);
	free(var_to_remove->value);
	free(var_to_remove);
}
