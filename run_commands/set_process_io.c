/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2024/10/31 14:40:46 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_process_io(int *input_file, int *output_file, t_pipe *incomming_pipe, t_pipe **outgoing_pipe)
{
	if (incomming_pipe && (*input_file == -1))
		input_from_pipe(incomming_pipe);
	if (*input_file != -1)
		input_from_file(input_file);
	if (outgoing_pipe && (*output_file == -1))
		output_to_pipe(outgoing_pipe);
	if (*output_file != -1)
		output_to_file(output_file);
}
