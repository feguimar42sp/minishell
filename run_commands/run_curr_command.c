/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_curr_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:36:10 by fernando          #+#    #+#             */
/*   Updated: 2024/10/31 14:24:44 by feguimar         ###   ########.fr       */
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
	env_path = ft_split(getenv("PATH"), ':');
	command_line = make_array(*b);
	pid = fork();
	if (pid == 0)
	{
		set_process_io(in_f, out_f, *in_p, out_p);
		execute_command(command_line, env_path);
	}
	else
		waitpid(pid, NULL, 0);
	if (*(*in_p) != NULL)
		free(*(*in_p));
	*in_p = out_p;
	clear_args_list(b);
	free_split(&env_path);
	free_split(&command_line);
}
