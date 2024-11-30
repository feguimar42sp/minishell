/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_first_env_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:45:53 by feguimar          #+#    #+#             */
/*   Updated: 2024/11/30 16:49:15 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	revome_first_env_var(void)
{
	t_envp_lst *first;

	first = *env_vars_list();
	(*env_vars_list()) = (*env_vars_list())->next;
	free(first->value);
	free(first->var);
	free(first);
}