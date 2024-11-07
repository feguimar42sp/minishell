/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_curr_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:36:10 by fernando          #+#    #+#             */
/*   Updated: 2024/10/31 21:56:21 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_curr_command(int *in_f, int *out_f, t_pipe **in_p, t_args_lst **b)
{
	char	**command_line;
	t_pipe	*out_p;
	pid_t	pid;
	char	**env_path;

	out_p = malloc(sizeof(t_pipe));
	pipe(*out_p);
	env_path = ft_split(ft_getenv("PATH"), ':');
	command_line = make_array(*b);
	pid = fork();
	if (pid == 0)
	{
		set_process_io(in_f, out_f, *in_p, out_p);
		execute_command(command_line, env_path);
	}
	else
		waitpid(pid, NULL, 0);
	if ((*in_p) != NULL)
		free((*in_p));
	close((*out_p)[1]);
	*in_p = out_p;
	clear_args_list(b);
	free_split(&env_path);
	free_split(&command_line);
}
