/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_from_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:47:57 by feguimar          #+#    #+#             */
/*   Updated: 2024/10/31 21:35:53 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	input_from_pipe(t_pipe *pipe)
{
	close((*pipe)[1]);
	dup2((*pipe)[0], STDIN_FILENO);
    close((*pipe)[0]);
}