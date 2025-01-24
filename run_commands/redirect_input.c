/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:25:10 by fernando          #+#    #+#             */
/*   Updated: 2025/01/23 19:30:11 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_input(t_command *command, t_args_lst **ptr)
{
	int	fd;

	(*ptr) = (*ptr)->next;
	fd = open((*ptr)->arg, O_RDONLY);
	if (fd == -1)
        write_stderr("Failed to open file", 1);
	command->input = fd;
}

