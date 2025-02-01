/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_curr_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:36:10 by fernando          #+#    #+#             */
/*   Updated: 2025/02/01 18:26:53 by feguimar         ###   ########.fr       */
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
		{
			if ((command_line[1] != NULL) && (command_line[2] != NULL))
			{
				write_stderr(" too many arguments",1);
				*current_exit_code() = 1;
			}
			else if ((command_line[1] != NULL) && (command_line[2] == NULL))
				*current_exit_code() = convert_exit_value(command_line[1]);
			else *current_exit_code() = 0;
			return ;
		}
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
	pid = fork();
	if (pid == 0)
	{
		rl_clear_history();
		if (!set_process_io(c, pipeline, total_blocks))
			free_process_io(c, &command_line, &env_path);
		if (!is_built_in(command_line[0], command_line, c, env_path))
			execute_command(command_line, env_path);
		exit(*current_exit_code());
	}
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

void	free_process_io(t_command *c, char ***command_line, char ***env_path)
{
	free_split(command_line);
	free_split(env_path);
	free_t_command(c);
	free_env_lst(env_vars_list(0));
	env_vars_list(1);
	close_all();
	free_args_list(args_list());
	exit(127);
}