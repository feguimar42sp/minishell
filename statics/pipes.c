/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:40:06 by fernando          #+#    #+#             */
/*   Updated: 2024/09/26 15:16:10 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*num_pipes(void)
{
	static int	p;

	return (&p);
}

t_pipe	**pipes(void)
{
	static t_pipe	*p;

	return (&p);
}
