/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2025/01/26 19:54:53 by fernando         ###   ########.fr       */
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
	if (is_input_from_heredoc((*ptr)->arg))
	{
		call_heredoc(command, ptr);
	}
}

void	call_heredoc(t_command *command, t_args_lst **ptr)
{
		pid_t	pid;

		close(command->here[0]);
		close(command->here[1]);
		pipe(command->here);
		command->input = command->here[0];
		pid = fork();
		handle_signals_exec();
		if (pid == 0)
		{
			handle_signals_heredoc();
			if (((*ptr)->next->is_quoted) == false)
				heredoc(command, ptr);
			else
				heredoc_expand(command, ptr);
		}
		waitpid(pid, NULL, 0);
		kill(pid, SIGKILL);
		if (*running_loop() == 1)
		{
			return ;
		}
		(*ptr) = (*ptr)->next;
		handle_signals();
	}
