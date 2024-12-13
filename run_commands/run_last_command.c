/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_last_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:57:33 by fernando          #+#    #+#             */
/*   Updated: 2024/12/13 17:41:55 by feguimar         ###   ########.fr       */
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
	if (((*b) != NULL) && (ft_strcmp((*b)->arg, "export") == 0))
		ft_export_run(command_line);
	if (((*b) != NULL) && (ft_strcmp((*b)->arg, "unset") == 0))
		ft_unset_run(command_line);
	*running_loop() = 1;
	pid = fork();
	if (pid == 0)
	{
		set_last_process_io(out_f, in_p);
		if (!is_built_in(command_line[0], command_line))
			execute_command(command_line, env_path);
		exit(*current_exit_code());
	}
	waitpid(pid, &status, WUNTRACED);
	*running_loop() = 0;
	if (WIFEXITED(status)) // catch status
		status = WEXITSTATUS(status);
	*current_exit_code() = status;
	close_files(out_f, &in_p);
	clear_args_list(b);
	free_split(&env_path);
	free_split(&command_line);
	//exit(*current_exit_code());
}
