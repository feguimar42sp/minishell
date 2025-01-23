/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:25:10 by fernando          #+#    #+#             */
/*   Updated: 2025/01/22 18:30:35 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_input(int run, t_args_lst **ptr, t_pipe *pipeline)
{
	int	fd;

	(*ptr) = (*ptr)->next;
	fd = open((*ptr)->arg, O_RDONLY);
	if (fd == -1)
	{
        write_stderr("Failed to open file", 1);
        //return;
    }
	if (run == 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		return ;
	}
    dup2(fd, pipeline[run - 1][0]);
    close(fd);
}

