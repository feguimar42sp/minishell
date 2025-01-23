/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2025/01/22 18:32:21 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirect(int run, t_pipe *pipeline, t_args_lst **ptr, int total_blocks)
{
	if (is_output_to_file((*ptr)->arg))
		redirect_output(run, ptr, pipeline, total_blocks);
	if (is_input_from_file((*ptr)->arg))
	{
	 	redirect_input(run, ptr, pipeline);
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
