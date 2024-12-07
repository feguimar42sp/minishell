/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:16:10 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 17:19:42 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_syntax.h"

// exit 2 when error
int	check_sequential_operators(t_args_lst **arg_lst)
{
	t_args_lst	*args;
	char		*operator_found;

	args = *arg_lst;
	operator_found = NULL;
	while (args && args->next)
	{
		if (args->type == operators && args->next->type == operators)
		{
			*current_exit_code() = 2;
			return (0);
		}
		args = args->next;
	}
	return (1);
}

int	handle_syntax(t_args_lst **arg_lst)
{
	if (check_sequential_operators(arg_lst)
}
