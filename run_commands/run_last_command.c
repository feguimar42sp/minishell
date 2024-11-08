/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_last_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:57:33 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 19:55:25 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	run_last_command(int *in_f, int *out_f, t_pipe *in_p, t_args_lst **b)
{
	char	**command_line;
	pid_t	pid;
	char	**env_path;
	int		status;

	status = 0;
	env_path = ft_split(ft_getenv("PATH"), ':');
	command_line = make_array(*b);
	if (!is_built_in(command_line[0], command_line))
	{
		pid = fork();
		if (pid == 0)
		{
			set_last_process_io(in_f, out_f, in_p);
			execute_command(command_line, env_path);
		}
		waitpid(pid, &status, 0);
	}
	*current_exit_code() = status;
	close_files(in_f, out_f, &in_p);
	clear_args_list(b);
}
