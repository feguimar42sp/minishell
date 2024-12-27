/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:37:08 by feguimar          #+#    #+#             */
/*   Updated: 2024/12/13 16:18:46 by feguimar         ###   ########.fr       */
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
		*current_exit_code() = 1;
		return ;
	}
	else
		*current_exit_code() = 0;
	prev_var_on_list = find_previous_var_in_list(name);
	prev_var_on_list->next = var_to_remove->next;
	free(var_to_remove->var);
	free(var_to_remove->value);
	free(var_to_remove);
}
