/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:25:10 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 21:58:44 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_export(t_args_lst **ptr)
{
	if (((*ptr)->next == NULL) || ((*ptr)->next->type == operators))
	{
		list_env_vars_ordered();
		return ;
	}
	(*ptr) = (*ptr)->next;
	while ((*ptr) != NULL)
	{
		if ((*ptr)->type == operators)
			break ;
		add_env_var((*ptr)->arg);
		(*ptr) = (*ptr)->next;
	}
	*current_exit_code() = 0;
}
