/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2024/12/13 20:05:28 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirect(t_pipe *in_file, int *out_file, t_args_lst **ptr)
{
	char	*buf;
	int		i;
	
	if (is_output_to_file((*ptr)->arg))
		redirect_output(out_file, ptr);
	if (is_input_from_file((*ptr)->arg))
	 	redirect_input(in_file, ptr);
	// if (is_export((*ptr)->arg))
	//  	run_export(ptr);
	if (is_input_from_heredoc((*ptr)->arg))
	{
		pid_t	pid;
		pid = fork();

		if (pid == 0)
		{
			if (((*ptr)->next->is_quoted) == false) // alterar nome da variavel
			{
				heredoc(in_file, ptr);
			}
			else
			{
				heredoc_expand(in_file, ptr);
			}
		}
		else
		{
			waitpid(pid, NULL, 0);
			if (*running_loop() == 1)
			{
				kill(pid, SIGKILL);
				buf = malloc(100);
				close((*in_file)[1]);
				i = read((*in_file[0]), buf, 100);
				while(i > 0)
				{
					i = read((*in_file)[0], buf, 100);
				}
				close((*in_file)[0]);
			}
			*running_loop() = 0;
		}
	}
}
