/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_curr_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:36:10 by fernando          #+#    #+#             */
/*   Updated: 2025/01/24 02:21:51 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_curr_command(t_command *c, t_pipe **pipeline, int total_blocks)
{
	char	**command_line;
	pid_t	pid;
	char	**env_path;

	env_path = ft_split(ft_getenv("PATH"), ':');
	command_line = make_array(c->comm);
	if (((c->comm) != NULL) && (ft_strcmp((c->comm)->arg, "export") == 0))
		ft_export_run(command_line);
	if (((c->comm) != NULL) && (ft_strcmp((c->comm)->arg, "unset") == 0))
		ft_unset_run(command_line);
	if (((c->comm) != NULL) && (ft_strcmp((c->comm)->arg, "cd") == 0))
		ft_cd_run(command_line);
	if (((c->comm) != NULL) && (ft_strcmp((c->comm)->arg, "exit") == 0))
		ft_exit_cmd(command_line);
	handle_signals_exec();
	pid = fork();
	if (pid == 0)
	{
		set_process_io(c, pipeline, total_blocks);
		if (!is_built_in(command_line[0], command_line))
			execute_command(command_line, env_path);
		exit(*current_exit_code());
	}
	// printf("ante do waitpid run %i\n", *run);
	// wait(&status);
	// printf("depois do waitpid run %i\n", *run);
	// kill(pid, SIGKILL);
	handle_signals();
	free_t_command(c);
	free_split(&env_path);
	free_split(&command_line);
}
