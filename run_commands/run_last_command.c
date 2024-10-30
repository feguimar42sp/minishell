/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_last_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:57:33 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 18:19:28 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	run_last_command(int *in_f, int *out_f, t_pipe *in_p, t_args_lst **b)
{
	char	**command_line;
	pid_t	pid;
	char	**env_path;

	env_path = ft_split(getenv("PATH"), ':');
	command_line = make_array(*b);
	pid = fork();
	if (pid == 0)
	{
		set_last_process_io(in_f, out_f, in_p);
		execute_command(command_line, env_path);
	}
	else
		waitpid(pid, NULL, 0);
	if (*in_p != NULL)
		free(*in_p);
	clear_args_list(b);
	free_split(&env_path);
	free_split(&command_line);
}
