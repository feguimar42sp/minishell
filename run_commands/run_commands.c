/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:12:46 by fernando          #+#    #+#             */
/*   Updated: 2024/10/25 00:08:27 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_commands(void)
{
	t_args_lst	*ptr;
	t_args_lst	*block;
	t_pipe		*pipeline;
	int			in_file;
	int			out_file;

	in_file = -1;
	out_file = -1;
	block = NULL;
	ptr = *args_list();
	pipeline = NULL;
	while (ptr)
	{
		if (ptr->type == operators)
		{
			if (ft_strcmp(ptr->arg, "|") == 0)
				run_curr_command(&in_file, &out_file, &pipeline, block);
			else
				parse_redirect(&in_file, &out_file, &ptr);
		}
		if (ptr->type == string)
			add_word(&block, ptr);
		ptr = ptr->next;
	}
	run_last_command(&in_file, &out_file, &pipeline, block);
}
