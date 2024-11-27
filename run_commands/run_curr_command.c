/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_curr_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:36:10 by fernando          #+#    #+#             */
/*   Updated: 2024/11/27 20:04:46 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_curr_command(int *out_f, t_pipe *in_p, t_args_lst **b)
{
	char	**command_line;
	t_pipe	out_p;
	pid_t	pid;
	char	**env_path;
	int		status;

	status = 0;
	pipe(out_p);
	env_path = ft_split(ft_getenv("PATH"), ':');
	command_line = make_array(*b);
	close((*in_p)[1]);
	if (!is_built_in(command_line[0], command_line))
	{
		pid = fork();
		if (pid == 0)
		{
			set_process_io(out_f, in_p, &out_p);
			execute_command(command_line, env_path);
		}
		waitpid(pid, &status, 0);
		pipe((*in_p));
		close(out_p[1]);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	*current_exit_code() = status;
	dump_from_file(out_p[0], (*in_p)[1]);
	clear_args_list(b);
	ft_free_split(env_path);
	ft_free_split(command_line);
}
