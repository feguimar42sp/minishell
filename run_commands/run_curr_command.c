/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_curr_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:36:10 by fernando          #+#    #+#             */
/*   Updated: 2025/02/01 16:47:50 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_built_ins(t_command *c, char **command_line, char ***e,
		t_pipe **pipeline)
{
	if (((c->comm) != NULL) && (ft_strcmp((c->comm)->arg, "export") == 0))
		ft_export_run(command_line);
	if (((c->comm) != NULL) && (ft_strcmp((c->comm)->arg, "unset") == 0))
		ft_unset_run(command_line);
	if (((c->comm) != NULL) && (ft_strcmp((c->comm)->arg, "cd") == 0))
		ft_cd_run(command_line);
	if (((c->comm) != NULL) && (ft_strcmp((c->comm)->arg, "exit") == 0))
	{
		if (count_blocks(*args_list()) != 1)
			return ;
		close_all();
		free(*pipeline);
		free_split(e);
		free_t_command(c);
		ft_exit_cmd(command_line);
	}
}

void	run_curr_command(t_command *c, t_pipe **pipeline, int total_blocks)
{
	char	**command_line;
	char	**env_path;
	pid_t	pid;

	if (ft_getenv("PATH") == NULL)
		env_path = ft_split("", ':');
	else
		env_path = ft_split(ft_getenv("PATH"), ':');
	command_line = make_array(c->comm);
	execute_built_ins(c, command_line, &env_path, pipeline);
	handle_signals_exec();
	pid = fork();
	if (pid == 0)
	{
		rl_clear_history();
		set_process_io(c, pipeline, total_blocks);
		if (!is_built_in(command_line[0], command_line, c, env_path))
			execute_command(command_line, env_path);
		exit(*current_exit_code());
	}
	handle_signals();
	if (c->not_last == 0)
		*last_pid() = pid;
	free_t_command(c);
	free_split(&env_path);
	free_split(&command_line);
}

void	print_split(char **tokens)
{
	int	i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s", tokens[i]);
		if (tokens[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	close_all(void)
{
	int	i;
	int	r;

	i = 0;
	while (i < 1024)
	{
		r = read(i, NULL, 0);
		if (r == 0)
			close(i);
		r = write(i, NULL, 0);
		if (r == 0)
			close(i);
		i++;
	}
}
