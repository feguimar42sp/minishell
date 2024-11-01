/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_last_process_io.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:00:22 by fernando          #+#    #+#             */
/*   Updated: 2024/10/31 21:43:27 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_last_process_io(int *in_f, int *out_f, t_pipe *in_p)
{
	set_process_io(in_f, out_f, in_p, NULL);
}
