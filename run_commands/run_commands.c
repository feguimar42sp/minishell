/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:12:46 by fernando          #+#    #+#             */
/*   Updated: 2025/01/29 02:16:22 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_commands(void)
{
	t_args_lst	*ptr;
	t_command	*command;
	int			run;

	ptr = *args_list();
	run = 0;
	command = new_command(run);
	while (ptr)
	{
		if (ptr->type == operators)
		{
			if (ft_strcmp(ptr->arg, "|") == 0)
			{
				push_command(command);
				run++;
				command = new_command(run);
			}
			else
				parse_redirect(command, &ptr);
		}
		else if (ptr->type == string)
			add_word(&(command->comm), ptr);
		if (ptr)
			ptr = ptr->next;
	}
	command->not_last = 0;
	push_command(command);
	call_list_commands();
}

int	count_blocks(t_args_lst *ptr)
{
	int	ret;

	ret = 1;
	while (ptr)
	{
		if (ptr->type == operators)
			if (ft_strcmp(ptr->arg, "|") == 0)
				ret++;
		ptr = ptr->next;
	}
	return (ret);
}

void	make_pipes(t_pipe **pipeline)
{
	int	total_blocks;
	int	i;

	if (*pipeline != NULL)
		free(*pipeline);
	total_blocks = count_blocks(*args_list());
	if (total_blocks == 1)
	{
		*pipeline = NULL;
		return ;
	}
	*pipeline = malloc(sizeof(t_pipe) * (total_blocks));
	i = 0;
	while (i < (total_blocks - 1))
	{
		pipe((*pipeline)[i]);
		i++;
	}
}

void	call_list_commands(void)
{
	static t_pipe		*pipeline;
	t_command			*command;
	int					total_blocks;
	int					i;

	make_pipes(&pipeline);
	total_blocks = count_blocks(*args_list());
	while (*command_lst() != NULL)
	{
		command = pop_command();
		run_curr_command(command, &pipeline, total_blocks);
	}
	i = 0;
	while ((i < (total_blocks - 1)))
	{
		close_t_pipe(pipeline[i]);
		i++;
	}
	waitpid(*last_pid(), &i, 0);
	if (WIFEXITED(i))
		*current_exit_code() = WEXITSTATUS(i);
	while (wait(&i) > 0);
}
