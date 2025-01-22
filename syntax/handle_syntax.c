/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:16:10 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/09 14:33:32 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_syntax.h"

/*
syntax error. should not output hi
1.
command: echo hi <
error message: function redirect error not doing anything
output: hi
exit code: 0 - should be: 2

2.
command: echo hi |  "|"
error message: if (path == NULL)
exit code: 127 - should be 2


*/

int	handle_syntax(t_args_lst **arg_lst)
{
	if (!check_sequential_operators(arg_lst))
	{
		*current_exit_code() = 2;
		return (0);
	}
	if (!check_unique_operator(arg_lst))
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
	return (1);
}
