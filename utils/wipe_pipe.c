/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:28:20 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/28 14:23:06 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wipe_pipe(t_pipe *in_file)
{
	char	*buf;
	int		i;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		buf = malloc(100);
		close((*in_file)[1]);
		i = read(((*in_file)[0]), buf, 100);
		while (i > 0)
		{
			i = read((*in_file)[0], buf, 100);
		}
		free(buf);
		close((*in_file)[0]);
	}
	else
	{
		waitpid(pid, NULL, 0);
		kill(pid, SIGKILL);
	}
}
