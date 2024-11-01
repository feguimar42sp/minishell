/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2024/10/31 21:03:24 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_process_io(int *input_file, int *output_file, t_pipe *incomming_pipe, t_pipe *outgoing_pipe)
{
	if (*input_file != -1)
		input_from_file(input_file);
	else if (incomming_pipe)
		input_from_pipe(incomming_pipe);
	if (*output_file != -1)
		output_to_file(output_file);
	else if (outgoing_pipe)
		output_to_pipe(outgoing_pipe);
}
