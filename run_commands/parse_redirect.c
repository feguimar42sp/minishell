/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2024/12/15 21:22:05 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirect(t_pipe *in_file, int *out_file, t_args_lst **ptr)
{
	if (is_output_to_file((*ptr)->arg))
		redirect_output(out_file, ptr);
	if (is_input_from_file((*ptr)->arg))
	{
		pipe(*in_file);
	 	redirect_input(in_file, ptr);
	}
	if (is_input_from_heredoc((*ptr)->arg))
	{
		pid_t	pid;
		pid = fork();

		pipe(*in_file);
		if (pid == 0)
		{
			handle_signals_heredoc();
			if (((*ptr)->next->is_quoted) == false) // alterar nome da variavel
				heredoc(in_file, ptr);
			else
				heredoc_expand(in_file, ptr);
		}
		else
		{
			waitpid(pid, NULL, 0);
			if (*running_loop() == 1)
			{
				free_args_lst(args_list());
				*ptr = NULL;
			}
		}
	}
}
