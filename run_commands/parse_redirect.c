/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 19:21:21 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirect(int *in_file, int *out_file, t_args_lst **ptr)
{
	if (is_output_to_file((*ptr)->arg))
		redirect_output(out_file, ptr);
	// if (is_input_from_file((*ptr)->arg))
	// 	redirect_input(in_file, ptr);
	// if (is_input_from_heredoc((*ptr)->arg))
	// 	heredoc(prev_out, ptr);
	if (in_file)
		return ;
}
