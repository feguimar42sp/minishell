/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_last_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:57:33 by fernando          #+#    #+#             */
/*   Updated: 2024/11/27 20:07:24 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_last_command(int *out_f, t_pipe *in_p, t_args_lst **b)
{
	char	**command_line;
	pid_t	pid;
	char	**env_path;
	int		status;

	status = 0;
	env_path = ft_split(ft_getenv("PATH"), ':');
	command_line = make_array(*b);
	close((*in_p)[1]);
	if (!is_built_in(command_line[0], command_line))
	{
		pid = fork();
		if (pid == 0)
		{
			set_last_process_io(out_f, in_p);
			execute_command(command_line, env_path);
		}
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status)) // catch status
			status = WEXITSTATUS(status);
	}
	*current_exit_code() = status;
	close_files(out_f, &in_p);
	clear_args_list(b);
	ft_free_split(env_path);
	ft_free_split(command_line);
}
