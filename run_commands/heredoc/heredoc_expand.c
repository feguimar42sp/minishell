/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:30:07 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/25 21:34:06 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc_expand(t_command *command, t_args_lst **ptr)
{
	char		*line;
	char		*expan_line;

	line = NULL;
	(*ptr) = (*ptr)->next;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write_human_stdout(">>", 0);
		line = get_next_line(STDIN_FILENO);
		line[ft_strlen(line) - 1] = '\0';
		if ((line != NULL) && (ft_strcmp((*ptr)->arg, line) != 0))
		{
			expan_line = expand_env_vars_heredoc(line);
			free(line);
			write(command->here[1], expan_line, ft_strlen(expan_line));
			free(expan_line);
		}
		else
			break ;
	}
	free(line);
	exit(0);
}
