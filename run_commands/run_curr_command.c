/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_curr_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:36:10 by fernando          #+#    #+#             */
/*   Updated: 2025/01/22 23:51:38 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_curr_command(int *run, t_pipe **pipeline, t_args_lst **b, int t)
{
	char	**command_line;
	pid_t	pid;
	char	**env_path;
	int		status;

	status = 0;
	env_path = ft_split(ft_getenv("PATH"), ':');
	command_line = make_array(*b);
	if (((*b) != NULL) && (ft_strcmp((*b)->arg, "export") == 0))
		ft_export_run(command_line);
	if (((*b) != NULL) && (ft_strcmp((*b)->arg, "unset") == 0))
		ft_unset_run(command_line);
	if (((*b) != NULL) && (ft_strcmp((*b)->arg, "cd") == 0))
		ft_cd_run(command_line);
	if (((*b) != NULL) && (ft_strcmp((*b)->arg, "exit") == 0))
		ft_exit_cmd(command_line);
	handle_signals_exec();
	pid = fork();
	if (pid == 0)
	{
		set_process_io(*run, pipeline, t);
		if (!is_built_in(command_line[0], command_line))
			execute_command(command_line, env_path);
		exit(*current_exit_code());
	}
	if (*pipeline != NULL)
		close((*pipeline)[*run][1]);
	// printf("ante do waitpid run %i\n", *run);
	 waitpid(pid, &status, WNOHANG);
	// printf("depois do waitpid run %i\n", *run);
	// kill(pid, SIGKILL);
	handle_signals();
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	*current_exit_code() = status;
	free_args_list(b);
	free_split(&env_path);
	free_split(&command_line);
	(*run)++;
}
