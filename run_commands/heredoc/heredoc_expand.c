/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:30:07 by feguimar          #+#    #+#             */
/*   Updated: 2024/11/29 19:29:38 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc_expand(t_pipe *file, t_args_lst **ptr)
{
	char		*line;
	char		*expan_line;

	line = NULL;
	(*ptr) = (*ptr)->next;
	while (1)
	{
		line = readline(">>");
		if ((line != NULL) && (ft_strcmp((*ptr)->arg, line) != 0))
		{
			expan_line = expand_env_vars_heredoc(line);
			free(line);
			write((*file)[1], expan_line, ft_strlen(expan_line));
			free(expan_line);
		}
		else
			break ;
	}
	free(line);
}
