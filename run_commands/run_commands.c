/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:12:46 by fernando          #+#    #+#             */
/*   Updated: 2025/01/22 17:42:22 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_commands(void)
{
	t_args_lst		*ptr;
	t_args_lst		*block;
	t_pipe			*pipeline;
	int				run;

	block = NULL;
	run = 0;
	ptr = *args_list();
	make_pipes(&pipeline);
	*running_loop() = 0;
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
		if (*running_loop() == 1)
		{
			free_args_list(&block);
			*running_loop() = 0;
			return ;
		}
		if (ptr)
			ptr = ptr->next;
	}
	run_last_command(&out_file, &pipeline, &block);
	free(pipeline);
}

int	count_blocks(t_args_lst		*ptr)
{
	int	ret;

	ret = 1;
	while(ptr)
	{
		if (ptr->type == operators)
			if (ft_strcmp(ptr->arg, "|") == 0)
				ret++;
		ptr = ptr->next;
	}
	return (ret);
}

void	make_pipes(t_pipe **pipeline)
{
	int	total_blocks;
	int	i;

	total_blocks = count_blocks(*args_list());
	*pipeline = malloc(sizeof(t_pipe*) * (total_blocks - 1));
	i = 0;
	while(i < (total_blocks - 1))
	{
		pipe((*pipeline)[i]);
		i++;
	}
}