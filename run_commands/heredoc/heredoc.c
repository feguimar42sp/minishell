/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:30:07 by feguimar          #+#    #+#             */
/*   Updated: 2025/02/01 12:22:17 by feguimar         ###   ########.fr       */
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
		printf("test line  *%s*\n", line);
		line[ft_strlen(line) - 1] = '\0';
		printf("test line no nl  *%s*\n", line );
		if ((line != NULL) && ((ft_strcmp((*ptr)->arg, line) != 0)))
		{
			printf("test line no nl in loop  *%s*\n", line);
			line[ft_strlen(line) - 1] = '\n';
			printf("test final line  *%s*\n", line);
			write(command->here[1], line, ft_strlen(line));
		}
		else
			break ;
		free(line);
	}
	free(line);
	exit(0);
}
