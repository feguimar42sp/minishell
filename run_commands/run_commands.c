/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:12:46 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 18:26:02 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_commands(void)
{
	t_args_lst		*ptr;
	t_args_lst		*block;
	t_pipe			pipeline;
	int				out_file;

	out_file = -1;
	block = NULL;
	ptr = *args_list();
	pipe(pipeline);
	while (ptr)
	{
		if (ptr->type == operators)
		{
			if (ft_strcmp(ptr->arg, "|") == 0)
				run_curr_command(&out_file, &pipeline, &block);
			else
				parse_redirect(&pipeline, &out_file, &ptr);
		}
		else if (ptr->type == string)
			add_word(&block, ptr);
		ptr = ptr->next;
	}
	run_last_command(&out_file, &pipeline, &block);
}
