/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2025/02/01 18:07:41 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirect(t_command *command, t_args_lst **ptr)
{
	if (is_input_from_heredoc((*ptr)->arg))
		call_heredoc(command, ptr, 0);
	if ((command->input == -1) || (command->output == -1))
		return ;
	if (is_output_to_file((*ptr)->arg))
		redirect_output(command, ptr);
	if (is_input_from_file((*ptr)->arg))
		redirect_input(command, ptr);
}

void	call_heredoc(t_command *command, t_args_lst **ptr, pid_t pid)
{
	close_t_pipe(command->here);
	pipe(command->here);
	command->input = command->here[0];
	pid = fork();
	handle_signals_exec();
	if (pid == 0)
	{
		rl_clear_history();
		handle_signals_heredoc();
		if (((*ptr)->next->is_quoted) == false)
			heredoc(command, ptr, NULL);
		else
			heredoc_expand(command, ptr, NULL, NULL);
		close(command->here[0]);
		close(command->here[1]);
		free(command);
		free_args_list(args_list());
		free_env_lst(env_vars_list(0));
		exit(0);
	}
	waitpid(pid, NULL, 0);
	if (*running_loop() == 1)
		return ;
	(*ptr) = (*ptr)->next;
	handle_signals();
}
