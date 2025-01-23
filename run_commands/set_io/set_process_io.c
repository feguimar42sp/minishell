/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2025/01/22 23:48:10 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_process_io(int run, t_pipe **pipeline, int t)
{
	if (run != (t - 1))
	{
		dup2((*pipeline)[run][1], STDOUT_FILENO);
		close((*pipeline)[run][1]);
		close((*pipeline)[run][0]);
		// write(STDOUT_FILENO, "teste!!!", 8);
	}
	if (run != 0)
	{
		dup2((*pipeline)[run - 1][0], STDIN_FILENO);
		close((*pipeline)[run - 1][0]);
		// close((*pipeline)[run - 1][1]);
	}
}
