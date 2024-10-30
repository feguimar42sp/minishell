/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_last_process_io.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:00:22 by fernando          #+#    #+#             */
/*   Updated: 2024/10/25 00:11:54 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_last_process_io(int *in_f, int *out_f, t_pipe *in_p)
{
	if (*in_f != -1)
		dup2(*in_f, STDIN_FILENO);
	if (*out_f != -1)
		dup2(*out_f, STDOUT_FILENO);
	if (in_p != NULL)
		dup2((*in_p)[0], STDIN_FILENO);
}
