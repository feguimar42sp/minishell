/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_last_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:57:33 by fernando          #+#    #+#             */
/*   Updated: 2024/11/20 12:19:47 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_last_command(int *in_f, int *out_f, t_pipe *in_p, t_args_lst **b)
{
	char	**command_line;
	pid_t	pid;
	char	**env_path;

	pid = fork();
	if (pid == 0)
	{
		env_path = ft_split(getenv("PATH"), ':');
		command_line = make_array(*b);
		set_last_process_io(in_f, out_f, in_p);
		execute_command(command_line, env_path);
	}
	else
		waitpid(pid, exit_status(), 0);
	close_files(in_f, out_f, &in_p);
	clear_args_list(b);
}
