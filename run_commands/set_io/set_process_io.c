/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2024/11/27 19:00:16 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_process_io(int *output_file, t_pipe *incomming_pipe, t_pipe *outgoing_pipe)
{
	input_from_pipe(incomming_pipe);
	if (*output_file != -1)
		output_to_file(output_file);
	else if (outgoing_pipe)
		output_to_pipe(outgoing_pipe);
}
