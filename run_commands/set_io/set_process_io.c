/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2025/01/24 02:25:34 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_process_io(t_command *command, t_pipe **pipeline, int t)
{
	int i;

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
	i = 0;
	while((i < (t - 1)))
	{
		printf("closing pipe n %i", i);
		close((*pipeline)[i][0]);
		close((*pipeline)[i][1]);
		i++;
	}
}

void	close_pipes( t_pipe **pipeline, int t)
{
	int	i;

	i = 0;
	while((i < (t - 1)))
	{
		printf("closing pipe n %i", i);
		close((*pipeline)[i][0]);
		close((*pipeline)[i][1]);
		i++;
	}
}
