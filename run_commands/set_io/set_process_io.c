/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 16:41:39 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_pipes(t_command *command, t_pipe **pipeline, int t)
{
	int	i;

	i = 0;
	close(command->here[1]);
	while ((i < (t - 1)))
	{
		close((*pipeline)[i][0]);
		close((*pipeline)[i][1]);
		i++;
	}
}

void	set_process_io(t_command *command, t_pipe **pipeline, int t)
{
	if ((command->input == -1) || (command->output == -1))
		exit(1);
	if (command->output != STDOUT_FILENO)
	{
		dup2(command->output, STDOUT_FILENO);
		close(command->output);
	}
	else if (command->not_last == 1)
		dup2((*pipeline)[command->run][1], STDOUT_FILENO);
	if (command->input != STDIN_FILENO)
	{
		dup2(command->input, STDIN_FILENO);
		close(command->input);
	}
	else if (command->run != 0)
		dup2((*pipeline)[command->run - 1][0], STDIN_FILENO);
	close_pipes(command, pipeline, t);
}
