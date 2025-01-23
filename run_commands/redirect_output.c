/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:33:46 by fernando          #+#    #+#             */
/*   Updated: 2025/01/22 18:29:13 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void redirect_output(int run, t_args_lst **ptr, t_pipe *pipeline, int t)
{
    int fd;

    fd = open_file(ptr);
	if (run == (t - 1))
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
		return ;
	}
    dup2(fd, pipeline[run][1]);
    close(fd);
}