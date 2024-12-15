/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2024/12/15 20:11:54 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirect(t_pipe *in_file, int *out_file, t_args_lst **ptr)
{
	if (is_output_to_file((*ptr)->arg))
		redirect_output(out_file, ptr);
	if (is_input_from_file((*ptr)->arg))
	 	redirect_input(in_file, ptr);
	if (is_input_from_heredoc((*ptr)->arg))
	{
		pid_t	pid;
		pid = fork();

		*running_loop() = 1;
		if (pid == 0)
		{
			if (((*ptr)->next->is_quoted) == false) // alterar nome da variavel
				heredoc(in_file, ptr);
			else
				heredoc_expand(in_file, ptr);
			*running_loop() = 0;
		}
		else
		{
			waitpid(pid, NULL, 0);
			if (*running_loop() == 1)
			{
				kill(pid, SIGKILL);
				wipe_pipe(in_file);
				while(*ptr != NULL)
					(*ptr) = (*ptr)->next;
				*running_loop() = 0;
			}
		}
	}
}
