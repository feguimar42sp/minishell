/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_first_env_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:45:53 by feguimar          #+#    #+#             */
/*   Updated: 2024/12/01 22:41:02 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	remove_first_env_var(void)
{
	t_envp_lst *first;

	first = *env_vars_list();
	(*env_vars_list()) = (*env_vars_list())->next;
	free(first->value);
	free(first->var);
	free(first);
}