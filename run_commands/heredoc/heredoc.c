/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:30:07 by feguimar          #+#    #+#             */
/*   Updated: 2025/02/01 12:26:59 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc(t_command *command, t_args_lst **ptr)
{
	char		*line;

	line = NULL;
	(*ptr) = (*ptr)->next;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write_human_stdout(">>", 0);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			write_stderr("Warning: here-document ended by EOF",1);
			break ;
		}
		line[ft_strlen(line) - 1] = '\0';
		if ((line != NULL) && ((ft_strcmp((*ptr)->arg, line) != 0)))
		{
			line[ft_strlen(line)] = '\n';
			write(command->here[1], line, ft_strlen(line));
		}
		else
			break ;
		free(line);
	}
	free(line);
	exit(0);
}
