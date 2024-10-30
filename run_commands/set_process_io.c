/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2024/10/25 12:00:31 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_process_io(int *in_f, int *out_f, t_pipe *in_p, t_pipe *out_p)
{
	if (in_p != NULL)
		dup2((*in_p)[0], STDIN_FILENO);
	if (*in_f != -1)
	{
		dup2(*in_f, STDIN_FILENO);
		close((*in_p)[0]);
		close((*in_p)[1]);
		free(in_p);
		in_p = NULL;
	}
	if (*out_f != -1)
		dup2(*out_f, STDOUT_FILENO);
	else
	{
		pipe(*out_p);
		dup2((*out_p)[1], STDOUT_FILENO);
	}
}
