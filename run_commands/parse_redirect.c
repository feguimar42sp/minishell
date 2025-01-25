/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2025/01/23 19:24:14 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirect(t_command *command, t_args_lst **ptr)
{
	if (is_output_to_file((*ptr)->arg))
		redirect_output(command, ptr);
	if (is_input_from_file((*ptr)->arg))
	{
	 	redirect_input(command, ptr);
	}
	// if (is_input_from_heredoc((*ptr)->arg))
	// {
	// 	pid_t	pid;
	// 	pid = fork();

	// 	handle_signals_exec();
	// 	pipe(*in_file);
	// 	if (pid == 0)
	// 	{
	// 		handle_signals_heredoc();
	// 		if (((*ptr)->next->is_quoted) == false)
	// 			heredoc(in_file, ptr);
	// 		else
	// 			heredoc_expand(in_file, ptr);
	// 	}
	// 	else
	// 	{
	// 		waitpid(pid, NULL, 0);
	// 		kill(pid, SIGKILL);
	// 		if (*running_loop() == 1)
	// 		{
	// 			return ;
	// 		}
	// 	}
	// 	handle_signals();
	// }
}
