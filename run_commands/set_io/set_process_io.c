/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2025/01/23 22:44:32 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_process_io(t_command *command, t_pipe **pipeline, int not_last)
{
	if (not_last != 0)
		if (command->output == STDOUT_FILENO)
		{
			dup2((*pipeline)[command->run][1], STDOUT_FILENO);
			close((*pipeline)[command->run][1]);
			close((*pipeline)[command->run][0]);
		}
	if (command->output != STDOUT_FILENO)
	{
		dup2(command->output, STDOUT_FILENO);
		close(command->output);
	}
	if (command->run != 0)
		if (command->input == STDIN_FILENO)
		{
			dup2((*pipeline)[command->run - 1][0], STDIN_FILENO);
			close((*pipeline)[command->run - 1][0]);
			close((*pipeline)[command->run - 1][1]);
		}
	if (command->input != STDIN_FILENO)
	{
		dup2(command->input, STDIN_FILENO);
		close(command->input);
	}
}
