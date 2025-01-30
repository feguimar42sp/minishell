/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:11 by fernando          #+#    #+#             */
/*   Updated: 2025/01/30 11:04:34 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	**command_lst(void)
{
	static t_command	*a;

	return (&a);
}

pid_t	*last_pid(void)
{
	static pid_t	a;

	return (&a);
}