/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:30:07 by feguimar          #+#    #+#             */
/*   Updated: 2024/12/13 17:50:00 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc(t_pipe *file, t_args_lst **ptr)
{
	char		*line;
	char		*line_add;
	int			i;

	line = NULL;
	(*ptr) = (*ptr)->next;
	while (1)
	{
		line = readline(">>");
		if ((line != NULL) && ((ft_strcmp((*ptr)->arg, line) != 0)))
		{
			line_add = malloc(ft_strlen(line) + 1);
			i = 0;
			while(line[i] != '\0')
			{
				line_add[i] = line[i];
				i++;
			}
			line_add[i++] = '\n';
			line_add[i] = '\0';
			write((*file)[1], line_add, ft_strlen(line_add));
		}
		else
			break ;
		free(line);
	}
	free(line);
}
