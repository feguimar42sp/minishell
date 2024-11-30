/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:37:08 by feguimar          #+#    #+#             */
/*   Updated: 2024/11/30 16:45:16 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void remove_env_var(char *name)
{
	t_envp_lst	*var_to_remove;
	t_envp_lst	*prev_var_on_list;

	if (name == NULL)
		return ;
	if (ft_strncomp( (*env_vars_list())->var, name, ft_strlen(name) + 1))
		remove_first_env_var();
	var_to_remove = find_var_node(name);
	prev_
}