/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:16:10 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/26 22:49:37 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_syntax.h"

/*
2.
command: echo hi |  "|"
error message: if (path == NULL)
exit code: 127 - should be 2
*/

int	handle_syntax(t_args_lst **arg_lst)
{
	if ((!check_sequential_operators(arg_lst))
		|| (!check_unique_operator(arg_lst)))
	{
		*current_exit_code() = 2;
		return (0);
	}
	if (!check_multiple_operators_in_node(arg_lst))
	{
		*current_exit_code() = 2;
		return (0);
	}
	if (!single_pipe_at_beginning(arg_lst))
	{
		*current_exit_code() = 2;
		return (0);
	}
	if (!check_input_redirect(arg_lst))
	{
		*current_exit_code() = 2;
		return (0);
	}
	return (1);
}
