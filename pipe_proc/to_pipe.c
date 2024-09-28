/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:47:32 by fernando          #+#    #+#             */
/*   Updated: 2024/09/26 17:06:21 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	to_pipe(int block)
{
	if ((*num_pipes()) == 0)
		return ;
	if (block != 0)
	{
		dup2((*pipes())[block - 1][0], STDIN_FILENO);
		close((*pipes())[block - 1][0]);
	}
	if (block != *num_pipes())
	{
		dup2((*pipes())[block][1], STDOUT_FILENO);
		close((*pipes())[block][1]);
	}
}

void	close_pipe(int block)
{
	if ((*num_pipes()) == 0)
		return ;
	if (block != 0)
	{
		close((*pipes())[block - 1][0]);
	}
	if (block != *num_pipes())
	{
		close((*pipes())[block][1]);
	}
}
