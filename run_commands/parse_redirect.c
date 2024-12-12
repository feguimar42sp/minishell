/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 21:39:53 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirect(t_pipe *in_file, int *out_file, t_args_lst **ptr)
{
	if (is_output_to_file((*ptr)->arg))
		redirect_output(out_file, ptr);
	if (is_input_from_file((*ptr)->arg))
	 	redirect_input(in_file, ptr);
	if (is_env((*ptr)->arg))
	 	set_env(ptr);
	if (is_export((*ptr)->arg))
	 	set_export(ptr);
	if (is_input_from_heredoc((*ptr)->arg))
	{
		if (((*ptr)->is_quoted) == true)
			heredoc(in_file, ptr);
		else
	 		heredoc_expand(in_file, ptr);
	}
	if (in_file)
		return ;
}
