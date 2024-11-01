/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_to_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:48:41 by feguimar          #+#    #+#             */
/*   Updated: 2024/10/31 21:37:03 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	output_to_pipe(t_pipe *pipe)
{
	close((*pipe)[0]);
	dup2((*pipe)[1], STDOUT_FILENO);
	close((*pipe)[1]);
}
