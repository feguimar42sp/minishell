/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleite-s <rleite-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:30:07 by feguimar          #+#    #+#             */
/*   Updated: 2025/02/01 14:15:55 by rleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc_expand(t_command *c, t_args_lst **ptr, char *line, char *e_l)
{
	(*ptr) = (*ptr)->next;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write_human_stdout(">>", 0);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			write_stderr("Warning: here-document ended by EOF", 1);
			break ;
		}
		line[ft_strlen(line) - 1] = '\0';
		if ((line != NULL) && (ft_strcmp((*ptr)->arg, line) != 0))
		{
			e_l = expand_env_vars_heredoc(line);
			free(line);
			write(c->here[1], e_l, ft_strlen(e_l));
			free(e_l);
		}
		else
			break ;
	}
	free(line);
}
